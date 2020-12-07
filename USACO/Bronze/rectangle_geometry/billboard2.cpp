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

int x[5],y[5];

void solve(){ //Your solution starts here.
	for (int i=1;i<=4;++i){
		cin >> x[i] >> y[i];
	}
	if (x[4]>=x[2] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1]){
		cout << 0;
	}
	else if (x[3]<=x[1] && y[3]<=y[1] && y[4]>y[1] && x[4]>=x[2]){
		cout << (x[2]-x[1])*(y[2]-y[4]);
	}
	else if (y[3]<y[2] && x[3]<=x[1] && y[4]>=y[2] && x[4]>=x[2]){
		cout << (x[2]-x[1])*(y[3]-y[1]);
	}
	else if (x[4]>x[1] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1]){
		cout << (x[2]-x[4])*(y[2]-y[1]);
	}
	else if (x[3]<x[2] && x[4]>=x[2] && y[4]>=y[2] && y[3]<=x[1]){
		cout << (x[3]-x[1])*(y[2]-y[1]);
	}
	else cout << (x[2]-x[1])*(y[2]-y[1]);
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
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
