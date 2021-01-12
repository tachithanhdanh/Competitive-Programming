#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using si = short int;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define endl "\n"
//Make sure to define this
//in case you accidentally use endl instead of "\n" to make a new line

#define hash_set unordered_set
#define hash_map unordered_map

//vector
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()
#define ins insert

#define lb lower_bound
#define ub upper_bound

//pairs and tuples
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

void setIO(string name =""){
//Compile with those flags and to get the fastest performance
//g++.exe -std=c++11 -DLOCAL ${file} -o ${file_base_name}.exe -Wl,--stack,268435456 -O2 && ${file_base_name}.exe
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
		#endif
	}
	return;
}

//constant initialization
const string yes="YES",no="NO";
//const ll MOD=1e9+7;
const ll MOD=998244353;
const ll maxn=1e4+10;
const ll INF=1e18;
 
//variables used for the current problem
int t=1,a,b;

int gcd(int a,int b){
	while (b){
		swap(a,b);
		b%=a;
	}
	return a;
}

void solve(){
	cin >> a >> b;
	cout << a/gcd(a,b) << endl << b/gcd(a,b);
	return;
}
// you should actually read the stuff below
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
//DELETE ALL THE DEBUG LINES BEFORE SUBMITTING PLEASE
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
	setIO("");
	//cin >> t;
	//int i=0;
	while (t--){
		//cout << "Case #" << ++i << ": ";
		solve();
		//cout << endl;
	}
	//solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}