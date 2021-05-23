# Python 3
# Author: Danh Ta Chi Thanh

for test_cases in range(int(input())): # read the first line, then execute for loop in range(0, the integer in that line)
	n = int(input())
	s = input()
	nondec = True
	for i in range(1,n):
		if (s[i] < s[i-1]):
			nondec = False
			break
	if (nondec):
		print(s)
		continue
	cnt = [0, 0]
	pos = 0
	while (s[pos] == '0'):
		pos += 1
	cnt[0] = pos
	pos = -1
	while (s[pos] == '1'):
		pos -= 1
	cnt[1] = -(pos+1)
	print((cnt[0]+1)*'0'+cnt[1]*'1')

	
		
