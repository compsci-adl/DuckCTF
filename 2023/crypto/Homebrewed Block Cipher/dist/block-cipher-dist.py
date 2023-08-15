import string

# Can only encrypt things in alphabet
alphabet = list(string.ascii_lowercase + '0{}')
KEY = "REDACTED"

def encrypt(b):
    # REDACTED

def encryptMessage(p):
    if len(p) % 2:
        p += b'0'

    blocks = [p[i:i+2] for i in range(0, len(p), 2)]
    enc = ''.join(encrypt(b) for b in blocks)

    return enc

def main():
    FLAG = b"redacted"
    print(f"Encrypted Flag: {encryptMessage(FLAG)}\n")

    while True:
        p = bytes(input("Input something to be encrypted: "), 'utf-8')
        print(f"{encryptMessage(p)}\n")

main()
