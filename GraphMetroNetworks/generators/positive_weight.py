from random import randint
N = 5
print(N, int(N * (N - 1)))
for i in range(1, N + 1):
	for j in range(i + 1, N + 1):
		print(i, j, randint(1, 10), randint(1, 10))
		print(j, i, randint(1, 10), randint(1, 10))
Q = N
qry = set()
while len(qry) < Q:
	u = randint(1, N)
	v = randint(1, N)
	if u != v:
		qry.add((u, v))
print(Q)
for i in qry:
	print(i[0], i[1])