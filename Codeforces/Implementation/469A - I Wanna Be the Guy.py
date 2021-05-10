# Python 3
# Author: Danh Ta Chi Thanh
import sys
import math
import os

n = int(input());
flag = [False]*n;
a = list(map(int,input().split()));
b = list(map(int,input().split()));
for i in range(1,len(a)):
	flag[a[i]-1] = True;
for i in range(1,len(b)):
	flag[b[i]-1] = True;
for i in flag:
	if (i == False):
		print("Oh, my keyboard!");
		break;
else:
	print("I become the guy.");