# Python 3
# Author: Danh Ta Chi Thanh

n = int(input())
a = list(map(int,input().split()))
cnt = [0] * (100001)
for i in a:
	cnt[i] += 1
dp = [0] * (100001)
dp[0], dp[1] = 0, cnt[1]
for i in range(2,100001):
	dp[i] = max(dp[i-1],dp[i-2]+cnt[i]*i)
print(dp[100000])