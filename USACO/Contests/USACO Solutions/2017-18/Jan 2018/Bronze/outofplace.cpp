#include <bits/stdc++.h>
using namespace std;

int n,a[101],b[101],cnt=-1; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i]; b[i]=a[i];
	}
	sort(b,b+n);
	for (int i=0;i<n;++i){
		cnt+=a[i]!=b[i];
	}
	cnt=max(0,cnt);
	cout << cnt;
	return 0;
}