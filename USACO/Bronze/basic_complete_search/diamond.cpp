#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

using ll = long long;
using uint = unsigned int;

#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

void setIO(string name=""){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
		freopen("error.err","w",stderr);
	}
	return;
}

int n,k,ans,cnt; vector<int> a;

void solve(){
	cin >> n >> k;
	a.resize(n);
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(all(a));
	for (int i=0;i<n;++i){
		cnt=1;
		for (int j=i+1;j<n;++j){
			if (a[j]-a[i]<=k) ++cnt;
			else break;
		}
		ans=max(cnt,ans);
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="diamond";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << "s" << endl;
	return 0;
}