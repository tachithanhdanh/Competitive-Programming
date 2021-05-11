# Python 3
# Author: Danh Ta Chi Thanh

n = int(input())
a = sorted(list(map(int,input().split())))
m = int(input())
b = sorted(list(map(int,input().split())))

ans = 0
for i in range(n):
	for j in range(m):
		if (abs(a[i]-b[j]) <= 1):
			ans += 1
			b[j] = 200
			break
print(ans)