# Python 3
# Author: Danh Ta Chi Thanh

N = int(input())
A = list(map(int,input().split()))
cnt = [0] * (N+1)
for i in A:
	cnt[i] += 1
for i in range(1,N+1):
	if (cnt[i] == 1):
		for j in range(N):
			if (A[j] == i):
				print(j+1)
				break
		break
else:
	print(-1)