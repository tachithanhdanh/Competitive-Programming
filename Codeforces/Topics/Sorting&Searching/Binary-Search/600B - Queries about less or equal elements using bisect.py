# Python 3
# Author: Danh Ta Chi Thanh

import bisect

n, m = map(int,input().split())
a = sorted(list(map(int,input().split())))
b = list(map(int,input().split()))
for x in b:
	print(bisect.bisect_right(a, x, 0, n),end=' ')
