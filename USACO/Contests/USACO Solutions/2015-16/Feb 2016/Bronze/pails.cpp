#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pails.in","r",stdin);
	freopen("pails.out","w",stdout);
	int a,b,c,ans=0;
	cin >> a >> b >> c;
	for (int i = 0; i < 1001; ++i) {
		if (a*i > c) break;
		for (int j = 0; j < 1001; ++j) {
			int n = a*i + b*j;
			if (n > c) break;
			ans = max(ans,n);
		}
	}
	cout << ans;
	return 0;
}
