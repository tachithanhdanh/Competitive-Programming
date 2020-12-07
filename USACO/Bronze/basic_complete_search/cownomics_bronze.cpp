#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <tuple>

using namespace std;

using ll = long long;
using uint = unsigned int;

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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

int n,m,ans; 
vector<string> spotty,plain; vector<bool> flag(110,true);

void solve(){
	cin >> n >> m;
	spotty.resize(n); plain=spotty;
	for (string& s: spotty){
		cin >> s;
		//cerr << s << endl;
	}
	for (string& s: plain){
		cin >> s;
		//cerr << s << endl;
	}
	for (int i=0;i<m;++i){
		for (int j=0;j<n;++j){
			for (int k=0;k<n;++k){
				if (spotty[j][i]==plain[k][i]){
					flag[i]=false;
				}
			}
		}
	} 
	for (int i=0;i<m;++i){
		ans+=flag[i];
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="cownomics";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}