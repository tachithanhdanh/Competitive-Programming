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
const int mod=1e9+7;
const int maxn=2e5+10;
const ll INF = 1e18;

//variables used for the current problem
int n,product,ans; //int fact[13];
vi divisors;

void solve(){
	cin >> n;
	//fact[0]=1;
	//FOR(i,1,13) fact[i]=fact[i-1]*i;
	for (int i=1;i*i<=n;++i){
		if (n%i==0){
			divisors.pb(i);
			if (n/i!=i) divisors.pb(n/i);
		}
	}
	sort(all(divisors));
	F0R(l,sz(divisors)) R0F(r,sz(divisors)) if (r-l == divisors[r]-divisors[l]){
		product=1;
		FOR(k,l,r+1){
			product*=divisors[k];
		}
		if (product==n) {
			++ans; //cerr << divisors[l]-1 << " " << divisors[r] << endl;
		}
	}
	//ans+=binary_search(all(fact),n);
	cout << ans;
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}