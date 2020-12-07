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
 
int n,a[1010],ans=INT_MAX,total;

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> a[i];
	}
	for (int i=1;i<=n;++i){
		total=0;
		for (int j=i+1;j<=n;++j){
			total+=a[j]*(j-i);
		}
		for (int j=i-1;j>=1;--j){
			total+=a[j]*(n-i+j);
		}
		ans=min(ans,total);
	}
	cout << ans;
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	freopen("cbarn.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("cbarn.out", "w", stdout); 
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