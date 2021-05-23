# Python 3
# Author: Danh Ta Chi Thanh

for test_cases in range(int(input())): # read the first line, then execute for loop in range(0, the integer in that line)
	n = int(input())
	s = list(input())
	s.reverse()
	ans = []
	flag, has0yet, has1yet, cnt0 = False, False, False, 0
	for i in s:
		if (i == '0'):
			cnt0 += 1
			has0yet = True
			# has1yet = False
		if (i == '1'):
			if (has0yet):
				if (cnt0):
					if (not has1yet or (has1yet and ans[-1] != '0')):
						ans.append('0')
					cnt0 = 0
			else:
				ans.append('1')
			has1yet = True
	# print("len(ans) =",len(ans))
	ans.reverse()
	print('0'*cnt0,end='')
	for i in ans:
		print(i,end='')
	print()
	
		
