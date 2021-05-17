# Python 3
# Author: Danh Ta Chi Thanh

a, b, c, d = map(int,input().split())
if (abs(a-b) <= d and abs(a-c) <= d and abs(b-c) <= d):
	print("Yes")
else:
	print("No")