# Python 3
# Author: Danh Ta Chi Thanh

# prefix sum?
for test_case in range(int(input())):
	n, k = map(int,input().split())
	a = list(map(int,input().split()))
	# counts peaks
	cnt = [0] * (n+1)
	for i in range(1,n-1):
		cnt[i+1] = cnt[i] + (a[i] > a[i-1] and a[i] > a[i+1])
	t, l = -1, -1
	for i in range(1,n-k+2):
		if (cnt[i+k-2]-cnt[i] > t):
			t, l = cnt[i+k-2]-cnt[i], i
	print(t+1,l)
