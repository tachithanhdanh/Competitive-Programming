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

ll l,n,rf,rb,x[100005],c[100005];
ll maxc,posc,pos,preposc,dis,timef,timeb,dtime;
ll ans;

void solve(){
	cin >> l >> n >> rf >> rb;
	for (int i=1;i<=n;++i){
		cin >> x[i] >> c[i];
		//cerr << x[i] << " " << c[i] << endl;
	}
	while (true){
		pos=posc=maxc=-1;
		for (int i=preposc+1;i<=n;++i){
			if (maxc<c[i]){
				//cerr << c[i] << endl;
				posc=i; maxc=c[i];
			}
		}
		//cerr << posc << " " << preposc << endl;
		dis=x[posc]-x[preposc];
		timef=rf*dis; timeb=rb*dis;
		dtime=timef-timeb;
		//cerr << dtime << endl;
		preposc=posc;
		if (posc==-1) break;
		ans+=dtime*maxc;
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
	string name="reststops";
	//string name="";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}