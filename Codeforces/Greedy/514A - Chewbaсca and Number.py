# Python 3
# Author: Danh Ta Chi Thanh

n = [int(x) for x in input()]
for i in range(0,len(n)):
	if (i == 0 and n[i] == 9):
		print(n[i],end='')
		continue
	print(min(n[i],9-n[i]),end='')