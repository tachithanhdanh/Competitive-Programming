#include<bits/stdc++.h>
using namespace std;

int n,a[1050],l,r,ans;

int main(){
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=359
	cin.tie(0)->sync_with_stdio(0);
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(a,a+n);
	l=1; r=n-1;
	for (int i=0;i<n;++i){
		for (l=i+1;l<n-1;++l){
			r=n-1;
			if (a[l]-a[i]>a[r]-a[l]) break;
			while (l<r && (a[r]-a[l])>2*(a[l]-a[i]) && (a[l]-a[i]<=a[r]-a[l])){
				--r;
			}
			if (a[l]-a[i]>a[r]-a[l] || l>=r) continue;
			while (l<r && (a[l]-a[i]<=a[r]-a[l])){
				--r; ++ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
