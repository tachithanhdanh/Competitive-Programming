# Python 3
# Author: Danh Ta Chi Thanh
import sys
import math

n = int(input());
a = list(map(int,input().split()));

for i in a:
	if (i):
		print("HARD");
		break;
else:
	print("EASY");