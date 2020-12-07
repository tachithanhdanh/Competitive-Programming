#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()

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
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

int n,q,a,b,c,k,v,ans; vector<pair<int,int>> adj[5005]; bool visited[5005];
queue<int> qu;

void bfs(int node){
	visited[node]=true;
	qu.push(node);
	while(!qu.empty()){
		int u=qu.front(); qu.pop();
		visited[u]=true;
		for (pair<int,int> v : adj[u]){
			if (!visited[v.f]){
				if (v.s>=k){
					++ans; qu.push(v.f);
				}
			}
		}
	}
	return;
}

void solve(){
	cin >> n >> q;
	for (int i=0;i<n-1;++i){
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c)); adj[b].pb(mp(a,c));
	}
	for (int i=0;i<q;++i){
		cin >> k >> v; 
		ans=0;
		memset(visited,0,sizeof(visited));
		bfs(v);
		cout << ans << endl;
	}
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
	string name="mootube";
	//string name="";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}