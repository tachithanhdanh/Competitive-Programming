# Python 3
# Author: Danh Ta Chi Thanh
import sys
import math

n, h = map(int,input().split());
a = list(map(int,input().split()));
global ans;
ans = 0;
for i in a:
	if (i > h):
		ans += 2;
	else:
		ans += 1;
print(ans);