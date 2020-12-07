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
 
short int n,ans[4],a,b,g; vector<vector<bool>> vb(4,vector<bool>(4,false));

void solve(){ //Your solution starts here.
	vb[1][1]=true; vb[2][2]=true; vb[3][3]=true;
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a >> b >> g;
		for (int i=1;i<4;++i){
			swap(vb[i][a],vb[i][b]);
			if (vb[i][g]) ++ans[i];
		}
	}
	sort(ans,ans+4);
	cout << ans[3];
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL); 
	freopen("shell.in", "r", stdin);  
	freopen("shell.out", "w", stdout);  
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