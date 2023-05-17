flag = b"quack{50M3T1m35_4Ll_Y0U_n33D_15_4_l1ttl3_150M0rPH15m!}"

n = 151
theta = 2*pi/n
a = cos(theta)
b = sin(theta)

# Provided in challenge description
M = matrix([[a, -b], [b, a]])

def check(M):
  m = (M^n).n() - identity_matrix(2)

  if m[0,0]^2+m[0,1]^2+m[1,0]^2+m[1,1]^2 < 0.00001:
    return

  print("Please contact the admins about an error")
  quit()

def coefficients(m, length):
  seq = [m]

  while len(seq) < length:
    seq.append(seq[-1]*m)

  return seq

def encrypt(M, m, flag):
  m = coefficients(m, len(flag))

  s = 0

  for c, a in zip(flag, m):
    s += (c*a) % n
  
  return (M^(s % n)).n()

def main():
  check(M)
  print("Hello! Welcome to the Argand-Noether encryption oracle!")
  print(M.n())

  while True:
    m = int(input("\nPlease input a number m: "))
    enc = encrypt(M, m, flag)
    print(f"Under {m}, the flag gets encrypted to")
    print(enc)

if __name__ == "__main__":
  main()
