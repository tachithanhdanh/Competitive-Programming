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
const int maxn=1e4+10;

//variables used for the current problem
int n,tmax,a[maxn];

bool check(int k){
	priority_queue<int,vector<int>,greater<int>> pq;
	int i=0,time=0;
	while (sz(pq)<k && i<n){
		pq.push(a[i]); ++i;
	}
	while (sz(pq)){ 
		time+=max(0,pq.top()-time); pq.pop();
		if (i<n){
			pq.push(a[i]+time); ++i;
		}
	}
	return time<=tmax;
}

int search(){
	int lo=1,hi=n,ans=n;
	while (lo<=hi){
		int mid = lo + (hi - lo)/2;
		if (check(mid)){
			ans=min(mid,ans); hi = mid - 1;
		}
		else lo = mid+1;
	}
	return ans;
}

void solve(){
    cin >> n >> tmax;
    for (int i=0;i<n;++i) cin >> a[i];
	cout << search() << endl;	
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
	setIO("cowdance");
	//cout.tie(NULL);
	/*
	cin >> t;
	for (int i=1;i<=t;++i){
		//cout << "Test " << i << endl;
		solve();
	}
	*/
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}
