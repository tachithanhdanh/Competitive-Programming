#include <bits/stdc++.h>
using namespace std;

int N,ans1,ans2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		ans1 += (a==1 && b==2) || (a==2 && b==3) || (a==3 && b==1);
		ans2 += (a==1 && b==3) || (a==3 && b==2) || (a==2 && b==1);
	}
	cout << max(ans1,ans2);
	return 0;
}
