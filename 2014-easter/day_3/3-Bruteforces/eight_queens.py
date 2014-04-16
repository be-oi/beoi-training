N = 10
attacked_by = [[0]*N for i in range(N)]
def add_attacker(start_row, start_col, val):
	for j in xrange(N-start_col):
		attacked_by[start_row][start_col+j] += val
		if start_row+j < N:
			attacked_by[start_row+j][start_col+j]+=val
		if start_row-j >= 0:
			attacked_by[start_row-j][start_col+j]+=val
result = [0]*N
def queens(current_col):
	global result
	if current_col == N:
		return True
	for i in xrange(N):
		if attacked_by[i][current_col] > 0:
			continue
		result[current_col]=i
		add_attacker(i, current_col, 1)
		if queens(current_col+1):
			return True
		add_attacker(i, current_col, -1)
	return False
queens(0)

for r in result:
	line = ""
	for i in range(N):
		if i == r:
			line += "x"
		else:
			line += "0"
	print line

