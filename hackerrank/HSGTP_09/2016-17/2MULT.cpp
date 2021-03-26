#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	int a, b;
	cin >> a >> b;
	int s1 = 0, s2 = 0;
	while (a) s1 += a % 10, a /= 10;
	while (b) s2 += b % 10, b /= 10;
	cout << s1 * s2;
	return 0;
}