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
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
 
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

int n,x,y; vector<pair<int,int>> v; ll a,b,area,ans;

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> x >> y;
		v.pb(mp(x,y));
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			for (int k=0;k<n;++k){
				//a=sqrt((v[i].f-v[j].f)*(v[i].f-v[j].f)+(v[i].s-v[j].s)*(v[i].s-v[j].s));
				//b=sqrt((v[i].f-v[k].f)*(v[i].f-v[k].f)+(v[i].s-v[k].s)*(v[i].s-v[k].s));
				//c=sqrt((v[k].f-v[j].f)*(v[k].f-v[j].f)+(v[k].s-v[j].s)*(v[k].s-v[j].s));
				//p=(a+b+c)/2;
				//area=p*(p-a)*(p-b)*(p-c);
				if (v[i].f==v[j].f && v[i].s==v[k].s){
					a=abs(v[i].s-v[j].s);
					b=abs(v[i].f-v[k].f);
					area=a*b;
				}
				ans=max(area,ans);
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
	string name="triangles";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
