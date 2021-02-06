#include <bits/stdc++.h>
using namespace std;

//vector
#define vt vector
#define all(x) begin(x), end(x) 
#define sz(x) (int)(x).size()
#define rsz resize

//variables used for the current problem
int n,k,ans,cnt; string a[101]; vt<vt<string>> vs; //map<string,int> m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("guess.in", "r", stdin); 
	freopen("guess.out", "w", stdout);
	cin >> n;
	vs.rsz(n);
	for (int i=0;i<n;++i){
		cin >> a[i] >> k;
		vs[i].rsz(k);
		for (int j=0;j<k;++j){
			cin >> vs[i][j];
			//++m[vs[i][j]];
		}
	}
	for (int i=0;i<n;++i) sort(all(vs[i]));
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			cnt=1;
			for (k=0;k<sz(vs[i]);++k){
				cnt+=binary_search(all(vs[j]),vs[i][k]);
			}
			ans=max(ans,cnt);
		}
	}
	cout << ans;
	return 0;
}