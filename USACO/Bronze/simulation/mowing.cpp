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
 
int s,n,ans=INT_MAX,pos1=2000,pos2=2000,step; char d;
int grass[4050][4050];

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> d >> s;
		for (int j=0;j<s;++j){
			if (d=='N') --pos1;
			else if (d=='S') ++pos1;
			else if (d=='E') ++pos2;
			else --pos2; 
			++step;
			//cerr << step << endl;
			if (grass[pos1][pos2]){
				//if (step-grass[pos1][pos2]<ans){
					//cerr << step << " conflict " << grass[pos1][pos2] << " at " << pos1 << " " << pos2 << endl;
				ans=min(ans,step-grass[pos1][pos2]);
				//}
				//else ans+=step-grass[pos1][pos2];
				//ans=max(ans,step-grass[pos1][pos2]);
				//cerr << "ans " << ans << endl;
			}
			grass[pos1][pos2]=step;
		}
	}
	if (ans==INT_MAX) cout << -1;
	else cout << ans;
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
	#ifndef ONLINE_JUDGE 
	freopen("mowing.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("mowing.out", "w", stdout); 
	#endif 
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
