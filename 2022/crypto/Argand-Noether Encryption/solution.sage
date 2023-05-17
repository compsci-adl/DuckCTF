from pwn import *

l = 100

def coefficients(m, length):
  seq = [m]

  while len(seq) < length:
    seq.append(round(seq[-1]*m))

  return seq

# Setting up the shell

shell = process('./test.sh')
M = shell.recvline_startswith(b'[')
n = round(2*pi/arccos(float(M.split(b' ')[2])))
theta = 2*pi/n

A = matrix(GF(n), 0, l)
b = []

# Receiving the data

for i in range(l):
  shell.recvline()
  shell.recvline()
  shell.sendline(str.encode(str(-i)))
  shell.recvline()
  M = shell.recvline()

  nums = [float(i) for i in re.findall(b"-?[\d]*[.][\d]+", M)]
  print(nums)
  r = round(arccos(nums[0])/theta)
  
  if nums[1] > 0:
    r = -r
  
  b.append(r)
  A = A.stack(matrix(GF(n), 1, l, coefficients(-i, l)))

b = vector(GF(n), b)

# Calculating the solution

print("Solution:")
sol = ''.join([chr(a) for a in A.solve_right(b)])
print(sol)
