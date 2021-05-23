# Python 3
# Author: Danh Ta Chi Thanh

t = int(input())
for i in range(t):
	n = int(input())
	w = sorted([int(x) for x in input().split()])
	# print(w)
	ans = 0
	for s in range(2*n+1):
		l, r, cnt = 0, n-1, 0
		while (l < r):
			if (w[l]+w[r] == s):
				cnt += 1
				l += 1
				r -= 1
			elif (w[l]+w[r] < s):
				l += 1
			else:
				r -= 1
		ans = max(ans,cnt)
	print(ans)
	