# Python 3
# Author: Danh Ta Chi Thanh

import sys

n, k = map(int,input().split())
a = sorted(list(map(int,input().split())))
if (not k):
	if (a[0] > 1):
		print(1)
	else:
		print(-1)
	sys.exit(0)
num = a[k-1]
counts = 0
for i in a:
	counts += num >= i
if (counts == k):
	print(num)
else:
	print(-1)
