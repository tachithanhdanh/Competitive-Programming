#include <sstream>
#include <iostream>
#include <fstream>
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
#define vt vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
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
		#ifdef LOCAL1 
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
	return;
}

int a[1024][1024],n,k,x,y,z,t,ans;

void solve(){
	cin >> n >> k;
	for (int i=0;i<n;++i){
		cin >> x >> y >> z >> t;
		++x; ++y; ++z; ++t;
		++a[x][y]; ++a[z][t]; --a[x][t]; --a[z][y];
	}
	for (int i=1;i<=1010;++i){
		for (int j=1;j<=1010;++j){
			//cout << a[i][j] << " ";
			a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			//cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i=1;i<=1001;++i){
		for (int j=1;j<=1001;++j){
			//a[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
			if (a[i][j]==k) ++ans;
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
	string name="paintbarn";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	#ifdef LOCAL1
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	#endif
	return 0;
}