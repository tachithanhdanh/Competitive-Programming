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

map<string,int> st; string a,b,c; int n,ans;
 
void solve(){ //Your solution starts here.
	//http://www.usaco.org/current/data/sol_citystate_silver_dec16.html
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=667
	//https://usaco.guide/solutions/usaco-667
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a >> b;
		if (a.substr(0,2)!=b){
			c=a.substr(0,2)+b;
			if (st.find(c)==st.end()){
				st.insert(make_pair(c,0));
			}
			++st[c];
		}
	}
	for (auto s: st){
		//cout << s.first << " " << s.second << endl;
		//cout << s.first << " " << s.second << endl;
		c=s.first.substr(2)+s.first.substr(0,2);
		//cerr << c << endl;
		if(st.find(c)!=st.end()) ans+=st[s.first]*st[c];
	}
	ans/=2;
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
	setIO("citystate");
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
