# Python 3
# Author: Danh Ta Chi Thanh

n, m, k = map(int,input().split());
a = [int(input()) for x in range(m+1)];
ans = 0;

for i in range(m):
	x = a[i] ^ a[m];
	counts = 0;
	while (x):
		counts += x & 1;
		x >>= 1;
	if (counts <= k):
		ans += 1;

print(ans);
