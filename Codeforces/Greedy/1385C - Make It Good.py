# Python 3
# Author: Danh Ta Chi Thanh

for t in range(int(input())): # read the first line, then execute for loop in range(0,first line integer)
	n, a = int(input()), list(map(int,input().split()))
	a.reverse()
	flag = True
	cnt = 0
	for i in range(1,n):
		if (flag and a[i] < a[i-1]):
			cnt += 1
			flag = False
		elif (flag == False and a[i] > a[i-1]):
			cnt += 1
			flag = True
		if (cnt > 1):
			print(n-i)
			break
	else:
		print(0)

			

