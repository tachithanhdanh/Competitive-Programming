# Python 3
# Author: Danh Ta Chi Thanh

n = int(input())
a = list(map(int,input().split()))
a.insert(0, 0)
b = sorted(a)
for i in range(1,n+1):
	a[i] += a[i-1]
	b[i] += b[i-1]

for query in range(int(input())):
	t, l, r = map(int,input().split())
	if (t == 1):
		print(a[r]-a[l-1])
	else:
		print(b[r]-b[l-1])