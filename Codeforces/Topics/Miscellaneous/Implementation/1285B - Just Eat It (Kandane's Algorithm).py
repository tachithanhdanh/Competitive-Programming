# Python 3
# Author: Danh Ta Chi Thanh

# oh wait
# 2 problems
# maximum subarray sum: if subarray all elements - min_elements
# maximum subsequence sum

def MSAS (a):
	s, cursum = -(10**14), -(10**14)
	for num in a: # maximum subarray sum
		cursum = max(cursum+num,num)
		s = max(s,cursum)
	return s

for test_case in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	b, c = list(a), list(a)
	b.pop(0)
	c.pop()
	s1, s2, s3 = sum(a), MSAS(b), MSAS(c)
	if (s1 > s2 and s1 > s3):
		print("YES")
	else:
		print("NO")