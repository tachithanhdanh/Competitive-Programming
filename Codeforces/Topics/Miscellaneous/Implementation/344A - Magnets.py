# Python 3
# Author: Danh Ta Chi Thanh
import sys
import math

n = int(input());
ans = 0;
magnet = premagnet = "";
for i in range(n):
	magnet = input();
	if (magnet != premagnet):
		ans += 1;
	premagnet = magnet;
print(ans);