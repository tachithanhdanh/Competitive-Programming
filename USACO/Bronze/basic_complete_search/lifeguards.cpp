#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

using ll = long long;
using uint = unsigned int;

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f first
#define s second

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
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

int n,a,b,mna,mxb,ans,cnt; vector<pair<int,int>> shift; int check[1005];

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a >> b;
		mna=min(a,mna); mxb=max(b,mxb);
		shift.push_back(make_pair(a,b));
		for (int j=a;j<b;++j){
			++check[j];
		}
	}
	for (auto x : shift){
		for (int i=x.f;i<x.s;++i){
			--check[i];
		}
		cnt=0;
		for (int i=mna;i<mxb;++i){
			if (check[i]) ++cnt;
		}
		//cerr << cnt << endl;
		for (int i=x.f;i<x.s;++i){
			++check[i];
		}
		ans=max(cnt,ans);
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="lifeguards";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}