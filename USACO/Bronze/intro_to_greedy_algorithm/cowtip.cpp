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
#include <numeric>
 
using namespace std;

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

int n,i_index,j_index,ans; bool cows[11][11],flag; char ch;

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			cin >> ch;
			cows[i][j]= ch == '1';
			cerr << cows[i][j];
		}
		cerr << endl;
	}
	cerr << endl;
	for (int i=n-1;i>-1;--i){
		for (int j=n-1;j>-1;--j){
			if (cows[i][j]){
				++ans;
				for (int a=0;a<=i;++a){
					for (int b=0;b<=j;++b){
						cows[a][b]=!cows[a][b];
					}
				}
				/*
				for (int a=0;a<n;++a){
					for (int b=0;b<n;++b){
						cerr << cows[a][b];
					}
					cerr << endl;
				}
				cerr << endl;
				*/
			}
		}
	}
	cout << ans << endl;
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
	string name="cowtip";
	//string name="";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}