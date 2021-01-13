#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using si = short int;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define vt vector
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

int n,a[1050],l,r,ans;

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	sort(a,a+n);
	l=1; r=n-1;
	for (int i=0;i<n;++i){
		for (l=i+1;l<n-1;++l){
			r=n-1;
			if (a[l]-a[i]>a[r]-a[l]) break;
			while (l<r && (a[r]-a[l])>2*(a[l]-a[i]) && (a[l]-a[i]<=a[r]-a[l])){
				--r;
			}
			if (a[l]-a[i]>a[r]-a[l] || l>=r) continue;
			while (l<r && (a[l]-a[i]<=a[r]-a[l])){
				--r; ++ans;
			}
		}
	}
	cout << ans << endl;
	return;
}
// you should actually read the stuff below
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
 
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=359
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}