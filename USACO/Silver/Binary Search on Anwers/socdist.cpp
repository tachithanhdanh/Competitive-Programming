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
#define mtp make_tuple

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
const int mod=1e9+7;
const int maxn=1e5+10;
const ll INF=1e18;

//variables used for the current problem
int N,M; ll ans,lo,hi,mid; vector<pair<ll,ll>> v;

void solve(){
	cin >> N >> M;
	v.rsz(M);
	for (auto &p : v) cin >> p.f >> p.s;
	sort(all(v));
	auto check = [&](const ll dist){
		ll cows=0,pos1=v[0].f;
		for (int i=0;i<M;++i){
			while (pos1<=v[i].s){
				pos1+=dist; ++cows;
			}
			if (i<M-1) pos1=max(pos1,v[i+1].f);
		}
		return cows>=N;
	};
	lo = 1, hi = INF;
	while (lo<=hi){
		mid = (lo + hi)/2;
		//cerr << mid << endl;
		if (check(mid)){
			lo =  mid + 1; ans = mid;
		}
		else hi = mid - 1;
	}
	cout << ans << endl;
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
	setIO("socdist");
	//cout.tie(NULL);
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}
