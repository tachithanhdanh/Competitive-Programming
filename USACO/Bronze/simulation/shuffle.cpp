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
 
int n,d; vector<int> a(110),b,c;

void solve(){ //Your solution starts here.
	cin >> n; b=a; c=a;
	for (int i=1;i<=n;++i){
		cin >> a[i];
	}
	cerr << endl;
	for (int i=1;i<=n;++i){
		cin >> b[i];
	}
	for (int i=0;i<3;++i){
		for (int j=1;j<=n;++j){
			c[j]=b[a[j]];
		}
		b=c;
	}
	for (int i=1;i<=n;++i){
		cout << b[i] << endl;
	}
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	freopen("shuffle.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("shuffle.out", "w", stdout); 
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