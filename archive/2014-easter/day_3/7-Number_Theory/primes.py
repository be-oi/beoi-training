MAXN = 1000000
non_primes = [False]*MAXN
primes = []

for i in range(2, MAXN):
	if non_primes[i]:
		continue
	primes.append(i)
	for j in range(i*i, MAXN, i):
		non_primes[j] = True
print primes
