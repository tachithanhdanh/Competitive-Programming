# Python 3
# Author: Danh Ta Chi Thanh

import bisect

n, m = map(int,input().split())
a = sorted(list(map(int,input().split())))
b = list(map(int,input().split()))
for x in b:
	# upper bound
	lo, hi = 0, n
	while (lo < hi):
		mid = (lo + hi)//2
		if (a[mid] > x):
			hi = mid
		else: # if a[mid] < x
			lo = mid + 1
	print(lo,end=' ')