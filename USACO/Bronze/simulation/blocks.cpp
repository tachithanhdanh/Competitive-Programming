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
 
int n,ans[26],cnt[26]; vector<vector<string>> vs(100,vector<string>(2,"")); string s;

void backtrack(int i){
	for (int j=0;j<2;++j){
		for (int k=0;k<vs[i][j].size();++k){ 
			++cnt[(vs[i][j][k])-'a'];
		}
		if (i==n-1){
			for (int m=0;m<26;++m){
				ans[m]=max(ans[m],cnt[m]);
				//cnt[m]=0;
			}
			//return;
		}
		else backtrack(i+1);
		for (int k=0;k<vs[i][j].size();++k){ 
			--cnt[(vs[i][j][k])-'a'];
		}
	}
}

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		for (int j=0;j<2;++j){
			cin >> vs[i][j];
		}
	}
	//cout << vs[0][0][0];
	backtrack(0);
	for (int i=0;i<26;++i){
		cout << ans[i] << endl;
	}
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	#ifndef ONLINE_JUDGE 
	freopen("blocks.in", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("blocks.out", "w", stdout); 
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