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
const int maxn=5e4+10;
const ll INF = 1e18;

//variables used for the current problem
int n; vector<ll> neg,pos; bool zero;
ll ans[4],res=-INF;

void solve(){
	//4 cases
	//pos * pos
	//neg * neg
	//min pos * max neg
	//0
	cin >> n;
	F0R(i,n){
		int a;
		cin >> a;
		if (a>0) pos.pb(a);
		else if (a<0) neg.pb(a);
		else zero=true;
	}
	sort(all(pos)); sort(all(neg));
	trav(a,ans) a = -INF;
	if (zero) ans[0]=0;
	if (sz(pos)>1) ans[1]=pos[sz(pos)-1]*pos[sz(pos)-2];
	if (sz(neg)>1) ans[2]=neg[0]*neg[1];
	if (sz(pos) && sz(neg)) ans[3]=neg[sz(neg)-1]*pos[0];
	trav(a,ans) res=max(res,a);
	cout << res;
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}