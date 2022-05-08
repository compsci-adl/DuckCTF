flag = b"quack{50M3T1m35_4Ll_Y0U_n33D_15_4_l1ttl3_150M0rPH15m!}"

n = 1000
theta = 2*pi/n
a = cos(theta)
b = sin(theta)

M = matrix([[a, -b], [b, a]])

print((M^flag[0] * M^flag[1] * M^flag[2]).n())
print((M^flag[2] * M^flag[1]).n())
print((M^flag[1] * M^flag[0]).n())

S = []
for i in range(1):
  s = identity_matrix(2)
  for j in range(i+1):
    s *= M^(flag[j])

  S.append(s.n())

#print(S)
