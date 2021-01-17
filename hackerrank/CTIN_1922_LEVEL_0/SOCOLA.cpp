#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

void setIO(string name = "") { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	else{
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7;
const int maxn=1e6+10;
const ll INF = 1e18;

//variables used for the current problem
int n;

void solve(){
	cin >> n;
	auto convert = [](int n){
		vi bin;
		int ans = 1;
		while (ans<n) ans<<=1;
		while (n){
			bin.pb(n&1);
			n>>=1;
		}
		int pos1,pos2;
		F0R(i,sz(bin)) if (bin[i]){
			pos1 = i; break;
		}
		R0F(i,sz(bin)) if (bin[i]){
			pos2 = i; break;
		}
		if (pos1==pos2) return pi(ans,0);
		else return pi(ans,pos2-pos1+1);
	};
	cout << convert(n).f << " " << convert(n).s;
    return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}