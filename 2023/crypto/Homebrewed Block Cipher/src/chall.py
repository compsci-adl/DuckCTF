#!/usr/local/bin/python3

import string

# Can only encrypt things in alphabet
alphabet = list(string.ascii_lowercase + '0{}')

# ================= KEY GENERATION ===================
import itertools, random, hashlib
alphabet2 = [bytes(c[0] + c[1],'ascii') for c in itertools.product(alphabet, alphabet)]
vals = alphabet2.copy()
random.shuffle(vals)
key = dict(zip(alphabet2, vals))
# ====================================================


def encrypt(b):
    H = hashlib.sha1(key[b])
    return H.hexdigest()

def encryptMessage(p):
    if len(p) % 2:
        p += b'0'

    blocks = [p[i:i+2] for i in range(0, len(p), 2)]
    enc = ''.join(encrypt(b) for b in blocks)

    return enc

def main():
    FLAG = b"quack{shortblockencryptionbad}"
    print(f"Encrypted Flag: {encryptMessage(FLAG)}\n")

    while True:
        p = bytes(input("Input something to be encrypted: "), 'utf-8')
        print(f"{encryptMessage(p)}\n")

main()
