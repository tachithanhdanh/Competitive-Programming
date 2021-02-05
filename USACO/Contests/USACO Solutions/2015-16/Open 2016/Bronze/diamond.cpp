#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
	int n,k;
	cin >> n >> k;
	vector<int> a;
	a.resize(n);
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int ans=0;
	for (int i=0;i<n;++i) {
		int cnt=1;
		for (int j=i+1;j<n;++j) {
			if (a[j]-a[i]<=k) ++cnt;
			else break;
		}
		ans=max(cnt,ans);
	}
	cout << ans;
	return 0;
}
