# Python 3
# Author: Danh Ta Chi Thanh

def reverse(s):
	""" see here: https://stackoverflow.com/questions/509211/understanding-slice-notation """
	return s[::-1]

n = int(input())
c = list(map(int,input().split()))
s = [[],[]]
for i in range(n):
	s[0].append(input())
for ss in s[0]:
	s[1].append(reverse(ss))
dp = [[10**18] * n,[10**18] * n]
dp[0][0], dp[1][0] = 0, c[0]
for i in range(1,n):
	if (s[0][i] >= s[0][i-1]):
		dp[0][i] = min(dp[0][i],dp[0][i-1])
	if (s[1][i] >= s[0][i-1]):
		dp[1][i] = min(dp[1][i],dp[0][i-1]+c[i])
	if (s[0][i] >= s[1][i-1]):
		dp[0][i] = min(dp[0][i],dp[1][i-1])
	if (s[1][i] >= s[1][i-1]):
		dp[1][i] = min(dp[1][i],dp[1][i-1]+c[i])
print(-1 if (dp[0][n-1] == dp[1][n-1] == 10**18) else min(dp[0][n-1],dp[1][n-1])) 