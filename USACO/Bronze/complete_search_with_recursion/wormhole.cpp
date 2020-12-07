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
using pii = pair<int,int>;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pob pop_back
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

const int mxN=12;
int x[mxN+1],y[mxN+1],n;
int partner[mxN+1];
int next_on_right[mxN+1];

bool cycle_exist(void){
	for (int start=1;start<=n;++start){
		int pos = start;
		for (int count = 0 ; count < n ; ++count){
			pos=next_on_right[partner[pos]];
		}
		if (pos){
			return true;
		}
	}
	return false;
}

//count all solutions
int dfs(void){
	int i,j,total=0;
	//is there any unpaired wormhole ?
	for (i=1;i<=n;++i){
		if (partner[i]==0){
			break;
		}
	}
	//if every wormhole is paired
	if (i>n){
		if (cycle_exist()) return 1;
		else return 0;
	}
	// try to recurse
	for (j=i+1;j<=n;++j){
		if (partner[j]==0){
			partner[i]=j;
			partner[j]=i;
			total+=dfs();
			partner[i]=partner[j]=0;
		}
	}
	return total;
}

void solve(){
	cin >> n;
	for (int i=1;i<n+1;++i){
		cin >> x[i] >> y[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (x[i] < x[j] && y[i] == y[j]){
				if (!next_on_right[i] || x[j] - x[i] < x[next_on_right[i]] - x[i]){
					next_on_right[i]=j;
				}
			}
		}
	}
	cout << dfs() << endl;
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
	string name="wormhole";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
