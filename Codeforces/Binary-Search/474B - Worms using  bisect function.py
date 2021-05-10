# Python 3
# Author: Danh Ta Chi Thanh

import bisect

n = int(input());
a = list(map(int,input().split()));
m = int(input());
q = list(map(int,input().split()));
a.insert(0,0);

for i in range(1,n+1):
	a[i] += a[i-1];
# 0 2 9 12 16 25

for qi in q:
	print(bisect.bisect_left(a,qi,0,n+1));