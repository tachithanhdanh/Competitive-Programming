# Python 3
# Author: Danh Ta Chi Thanh

s = input()
n = list(map(int,input().split()))
p = list(map(int,input().split()))
r = int(input())
cnt = [0]*3
for c in s:
	if (c == 'B'):
		cnt[0] += 1
	elif (c == 'S'):
		cnt[1] += 1
	else:
		cnt[2] += 1
fi = 10 ** 18
for i in range(len(n)):
	if (not cnt[i]):
		continue
	fi = min(fi, n[i] // cnt[i])
for i in range(len(n)):
	n[i] -= fi * cnt[i]
# print(fi)
def check(x): # check function for binary search
	needed = x * (sum(a * b for a, b in zip(cnt, p)))
	# print(needed)
	for i in range(len(n)):
		needed -= min(x * cnt[i], n[i]) * p[i]
	# print(needed)
	return r >= needed
# print(check(1000))
lo, hi = 0, 10 ** 18
while (lo < hi):
	mid = (lo + hi + 1) // 2
	if (check(mid)):
		lo = mid
	else:
		hi = mid - 1

print(fi + lo)