#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	//Read input from STDIN, then print the output to STDOUT.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b < c ||  d < a) cout << (b - a) + (d - c);
	else cout << max(b,d)-min(a,c);
	return 0;
}

