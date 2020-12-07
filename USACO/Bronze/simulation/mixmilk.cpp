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
 
int c[3],m[3],tmp;

void solve(){ //Your solution starts here.
	for (int i=0;i<3;++i){
		cin >> c[i] >> m[i];
	}
	for (int i=0;i<100;++i){
		if (i%3==0){
			tmp=min(m[0],c[1]-m[1]);
			m[0]-=tmp;
			m[1]+=tmp;
		}
		else if (i%3==1){
			tmp=min(m[1],c[2]-m[2]);
			m[1]-=tmp;
			m[2]+=tmp;
		}
		else {
			tmp=min(m[2],c[0]-m[0]);
			m[2]-=tmp;
			m[0]+=tmp;
		}
	}
	cout << m[0] << endl << m[1] << endl << m[2];
	return;
}
// you should actually read the stuff at the bottom
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout.tie(NULL);
	freopen("mixmilk.in", "r", stdin); 
	//freopen("error.txt", "w", stderr); 
	freopen("mixmilk.out", "w", stdout); 
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