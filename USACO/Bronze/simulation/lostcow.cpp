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
 
int x,y,a,b,z=1,ans,cnt=1;

void solve(){ //Your solution starts here.
	cin >> x >> y;
	a=x;
	while(a!=y){
		if (cnt&1){
			b=x+z;
		}
		else b=x-z;
		z*=2; ++cnt;
		while(a!=b){
			if (a<b) ++a;
			else --a;
			++ans; 
			if (a==y){
				cout << ans; return;
			}
		}
	}
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	#ifndef ONLINE_JUDGE 
	freopen("lostcow.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("lostcow.out", "w", stdout); 
	#endif 
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
 
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/