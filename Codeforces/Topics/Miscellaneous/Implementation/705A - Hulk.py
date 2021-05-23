# Python 3
# Author: Danh Ta Chi Thanh
import sys
import math

n = int(input());
for i in range(1,n+1):
	if (i&1):
		print("I hate ", end='');
	else:
		print("I love ", end='');
	if (i != n):
		print("that ", end= '');
	else:
		print("it");