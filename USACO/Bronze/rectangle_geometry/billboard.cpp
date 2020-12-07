#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
//#include <cmath>
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

vector<vector<bool>> check(2050,vector<bool>(2050,false));
int ans,x1,x2,y11,y2;

void solve(){ //Your solution starts here.
	for (int i=0;i<3;++i){
		cin >> x1 >> y11 >> x2 >> y2;
		x1+=1000; x2+=1000; y11+=1000; y2+=1000;
		for (int x=x1;x<x2;++x){
			for (int y=y11;y<y2;++y){
				if (i<2) check[x][y]=true;
				else check[x][y]=false;
			}
		}
	}
	for (int i=0;i<2050;++i){
		for (int j=0;j<2050;++j){
			ans+=check[i][j];
		}
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
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
