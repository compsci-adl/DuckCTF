

# This file was *autogenerated* from the file server.sage
from sage.all_cmdline import *   # import sage library

_sage_const_151 = Integer(151); _sage_const_2 = Integer(2); _sage_const_0 = Integer(0); _sage_const_1 = Integer(1); _sage_const_0p00001 = RealNumber('0.00001')
flag = b"quack{50M3T1m35_4Ll_Y0U_n33D_15_4_l1ttl3_150M0rPH15m!}"
#flag = b"Dog"

n = _sage_const_151 
theta = _sage_const_2 *pi/n
a = cos(theta)
b = sin(theta)

# Provided in challenge description
M = matrix([[a, -b], [b, a]])

def check(M):
  m = (M**n).n() - identity_matrix(_sage_const_2 )
  if m[_sage_const_0 ,_sage_const_0 ]**_sage_const_2 +m[_sage_const_0 ,_sage_const_1 ]**_sage_const_2 +m[_sage_const_1 ,_sage_const_0 ]**_sage_const_2 +m[_sage_const_1 ,_sage_const_1 ]**_sage_const_2  < _sage_const_0p00001 :
    return
  print("Please contact the admins about an error")
  quit()

def coefficients(m, length):
  seq = [m]

  while len(seq) < length:
    seq.append(seq[-_sage_const_1 ]*m)

  return seq

def encrypt(M, m, flag):
  m = coefficients(m, len(flag))

  s = _sage_const_0 

  for c, a in zip(flag, m):
    s += (c*a) % n
  
  return (M**(s % n)).n()

def main():
  check(M)
  print("Hello! Welcome to Noether encryption oracle. Let us know if you're able to break it!")
  print(M.n())

  while True:
    m = int(input("\nPlease input a number m: "))
    enc = encrypt(M, m, flag)
    print(f"Under {m}, the flag gets encrypted to")
    print(enc)

if __name__ == "__main__":
  main()
