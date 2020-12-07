#include <bits/stdc++.h>
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
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()
#define ins insert
#define lb lower_bound
#define up upper_bound

//pairs and tuples
#define f first
#define s second
#define mp make_pair
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".INP").c_str(),"r",stdin);
		freopen((name+".OUT").c_str(),"w",stdout);
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

long long a[251][251],t[251],tMax[251][251],n,m,q;

void solve(){
	cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)cin >> t[i];
    for (int i = 1; i <= m; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == 0)a[i][j] = 100000000;
            tMax[i][j] = max(t[i],t[j]);
        }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][j] + tMax[i][j] > a[i][k] + a[k][j] + max(tMax[i][k],tMax[k][j]))
                    a[i][j] = a[i][k] + a[k][j], tMax[i][j] = max(tMax[i][k],tMax[k][j]);
    for (int i = 1; i <= q; ++i){
        ll x,y; cin >> x >> y;
        //cout << x << endl << y << endl;
        cout << a[x][y] + tMax[x][y] << '\n';
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
	//string name="rental";
	string name="CHIPHI";
	setIO(name);
	//cout.tie(NULL);
	//generate();
	//cin >> t;
	//while (t--)
	solve();
	#ifdef LOCAL1
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	#endif
	return 0;
}