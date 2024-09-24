from Crypto.Util.number import long_to_bytes as l2b
from gmpy2 import sqrt, mpz, get_context
from math import ceil, lcm

from output import n, e, ct

get_context().precision=2048
x = sqrt(mpz(n))
x = ceil(x)

d = sqrt(x ** 2 - n)
p = int(x - d)
q = int(x + d)

assert p * q == n

l = lcm(p - 1, q - 1)
d = pow(e, -1, l)

pt = pow(ct, d, n)
print(l2b(pt).decode('utf-8'))
