#include <bits/stdc++.h>
#define int long long
using namespace std;

int T,n;

int32_t main() {
	cin>>T;
	while(T--) {
		cin>>n;
		int tmp=round(pow(n,1.0/3.0));
		cout<<(tmp*tmp*tmp==n?"YES":"NO")<<'\n';
	}
}
