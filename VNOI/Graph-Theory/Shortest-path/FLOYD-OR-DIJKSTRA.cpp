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
const int maxn=1e2+10;
const ll INF=1e18;

//variables used for the current problem
int n,m,q,dist[maxn][maxn],Next[maxn][maxn],a,b,c;

//https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/
//https://vietcodes.github.io/algo/floyd#truy-v%E1%BA%BFt-%C4%91%C6%B0%E1%BB%9Dng-%C4%91i
//https://codeforces.com/group/FLVn1Sc504/contest/274491/problem/M

void solve(){
    cin >> n >> m >> q;
    for (int i=1;i<=n;++i){
    	for (int j=1;j<=n;++j){
    		if (i!=j) dist[i][j]=dist[j][i]=mod;
    	}
    }
    
    for (int i=0;i<m;++i){
    	cin >> a >> b >> c;
    	dist[a][b]=dist[b][a]=c;
    	Next[a][b]=b; Next[b][a]=a;
    }
    for (int k=1;k<=n;++k){
    	for (int i=1;i<=n;++i){
    		for (int j=1;j<=n;++j){
    			if (dist[i][j] > dist[i][k] + dist[k][j]){
    				dist[i][j] = dist[i][k] + dist[k][j];
    				Next[i][j] = Next[i][k];
    			}
    		}
    	}
    }
    while (q--){
    	cin >> c >> a >> b;
    	if (c) {
    		vector<int> path;
    		while (a!=b){
    			path.pb(a);
    			a = Next[a][b];
    		}
    		path.pb(b);
    		cout << sz(path);
    		for (int node : path){
    			cout << " " << node;
    		}
    		cout << endl;
    	}
    	else cout << dist[a][b] << endl;
    }
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
	//cout.tie(NULL);
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}