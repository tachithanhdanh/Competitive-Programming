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
 
int n,m,a[105],b[105],ans,c,d,e;

void solve(){ //Your solution starts here.
	cin >> n >>m; e=1;
	for (int i=0;i<n;++i){
		cin >> c >> d;
		for (int j=e;j<e+c;++j){
			a[j]=d;
		}
		e+=c;
	}
	e=1;
	for (int i=0;i<m;++i){
		cin >> c >> d;
		for (int j=e;j<e+c;++j){
			b[j]=d;
		}
		e+=c;
	}
	for (int i=1;i<=100;++i){
		ans=max(ans,b[i]-a[i]);
	}
	cout << ans;
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL); 
	freopen("speeding.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("speeding.out", "w", stdout); 
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