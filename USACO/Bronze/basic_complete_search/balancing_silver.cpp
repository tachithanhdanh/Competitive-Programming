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

int n,x[1010],y[1010],a,b,section[5],ans=INT_MAX,cnt[4],mn,mx; vector<pair<int,int>> v; 

int find_ans(){
	int ans=0;
	memset(section,0,sizeof(section));
	for (pair<int,int> p : v){
		if (p.f<a && p.s>b){
			++section[1];
		}
		else if (p.f>a && p.s>b){
			++section[2];
		}
		else if (p.f>a && p.s<b){
			++section[3];
		}
		else if (p.f<a && p.s<b){
			++section[4];
		}
	}
	for (int i=0;i<5;++i){
		ans=max(ans,section[i]);
	}
	return ans;
}

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> x[i] >> y[i];
		v.pb(mp(x[i],y[i]));
	}
	//cerr << ans << endl;
	sort(x,x+n); sort(y,y+n);
	mn=min(n,n/2+120); mx=max(0,n/2-120);
	for (int i=mx;i<mn;++i){
		for (int j=mx;j<mn;++j){
			a=x[i]+1; b=y[j]+1;
			memset(cnt,0,sizeof(cnt));
			cnt[0]=find_ans();
			//cerr << m << endl;
			a=x[i]-1; b=y[j]+1;
			cnt[1]=find_ans();
			a=x[i]+1; b=y[j]-1;
			cnt[2]=find_ans();
			a=x[i]-1; b=y[j]-1;
			cnt[3]=find_ans();
			for (int i=0;i<4;++i){
				ans=min(ans,cnt[i]);
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
	string name="balancing";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
