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
 
#define endl "\n" 
#define ll long long  
#define hash_set unordered_set 
#define hash_map unordered_map  

int n,a[105],t,cnt,ans=1,dif; bool flag;
vector<bool> check((int)1e9+7,false); vector<int> v,vv;

void solve(){ //Your solution starts here.
	// 5 1 2 4 7 11
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	for (int i=0;i<n;++i){
		t=0; cnt=0; flag=true;
		for (int j=0;j<n;++j){
			check[a[j]]=false;
		}
		v.clear(); vv.clear(); v.push_back(a[i]);
		while (flag){
			flag=false;
			for (int j=0;j<n;++j){
				dif=INT_MAX;
				for (int x : v){
					dif=min(dif,abs(x-a[j]));
				}
				if (dif<=t && !check[a[j]]){
					++cnt; check[a[j]]=true; flag=true;
					vv.push_back(a[j]);
				}
			}
			v=vv; vv.clear(); ++t;
		}
		ans=max(ans,cnt); 
	}
	cout << ans;
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
