from Crypto.Util.number import getPrime, bytes_to_long as b2l
from Crypto.Math.Primality import miller_rabin_test
from random import randint
from math import lcm, gcd

from flag import FLAG

# Generate key
p = getPrime(1024)
maxDiff = min(2 ** 64 - 1, p)

q = p - 1

# Note: miller rabin is a primality test
while miller_rabin_test(q, 3) == False:
    q = p - randint(0, maxDiff)

# Encrypt flag with RSA
n = p * q
l = lcm(p - 1, q - 1)
e = 65537

assert gcd(e, l) == 1

ct = pow(b2l(FLAG), e, n)

with open('output.py', 'w') as f:
    f.write(f"n={n}\ne={e}\nct={ct}")
