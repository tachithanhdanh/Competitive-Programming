# Python 3
# Author: Danh Ta Chi Thanh

n, m, k = map(int,input().split());
a = [];
for i in range(m+1):
	num = int(input());
	a.append(num);
ans = 0;

for i in range(m):
	bit, counts = 1, 0;
	while (bit < (1 << 22)):
		b1, b2 = bit & a[i], bit & a[m];
		counts += bool(b1 ^ b2);
		bit <<= 1;
	if (counts <= k):
		ans += 1;

print(ans);
