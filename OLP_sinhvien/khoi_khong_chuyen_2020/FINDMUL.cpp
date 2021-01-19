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
#define trav(a,x) for (auto& a: x)

void setIO(string name = "") { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".INP").c_str(), "r", stdin);
		freopen((name+".OUT").c_str(), "w", stdout);
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
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
ll a,b,n,lcm,lo,hi,mid,ans;

void solve(){
	cin >> a >> b >> n;
	auto gcd = [](ll a,ll b){
		if (b>a) swap(a,b);
		while (b){
			swap(a,b);
			b = b%a;
		}
		return a;
	};
	auto counts = [](const ll &a,const ll &b,const ll &lcm,const ll &num){
		return num/a + num/b - num/lcm;
	};
	lcm = (a*b)/gcd(a,b);
	lo = 0, hi = INF;
	while (lo<=hi){
		mid = (lo + hi)/2;
		const ll cnt = counts(a,b,lcm,mid);
		if (cnt < n){
			lo = mid + 1;
		}
		else{
			ans = mid;
			hi = mid - 1;
		}
	}
	cout << ans << endl;
	return;
}

void brute_force(){
	vector<bool> test(MOD,false);
	F0R(i,MOD){
		test[i]= i%a==0 || i%b==0;
	}
	test[0]=false;
	int cnt = 0;
	F0R(i,MOD){
		cnt+=test[i];
		if (cnt==n) {
			cout << i << endl; return;
		}
	}
}

int main() {
	setIO(FINDMUL);
	solve();
	//brute_force();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}