# Python 3
# Author: Danh Ta Chi Thanh

n = int(input());
a = list(map(int,input().split()));
m = int(input());
q = list(map(int,input().split()));
a.insert(0,0);

for i in range(1,n+1):
	a[i] += a[i-1];

for qi in q:
	lo, hi = 0, n;
	while (lo < hi):
		mid = (lo + hi)//2;
		if (a[mid] >= qi):
			hi = mid;
		else:
			lo = mid + 1;
	print(lo);

