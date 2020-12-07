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

using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
 
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mtp make_tuple

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

int n,t,a,b,c,turns[101],k,mink=500,maxk,numcow; bool patientzero[101];
string cows,test; vector<tuple<int,int,int>> v;
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1037
//http://www.usaco.org/current/data/sol_tracing_bronze_open20.html
//https://usaco.guide/bronze/intro-complete

void solve(){ //Your solution starts here.
	cin >> n >> t;
	cin >> cows;
	for (int i=0;i<t;++i){
		cin >> a >> b >> c;
		--b; --c;
		v.pb(mtp(a,b,c)); 
	}
	sort(all(v)); test=cows;
	for (int i=0;i<n;++i){
		if (cows[i]=='1'){
			k=0;
			while(k<=t){
				fill(all(test),'0');
				test[i]='1';
				fill(all(turns),k);
				for (int j=0;j<t;++j){
					b=get<1>(v[j]); c=get<2>(v[j]);
					if (test[b]=='1' && turns[b] && test[c]=='0'){
						--turns[b]; test[c]='1';
					}
					else if (test[c]=='1' && turns[c] && test[b]=='0'){
						--turns[c]; test[b]='1';
					}
					else if (test[b]=='1' && test[c]=='1'){
						if (turns[c]) --turns[c];
						if (turns[b]) --turns[b];
					}
				}
				if (test==cows) {
					if (mink>k) mink=k;
					if (maxk<k) maxk=k;
					patientzero[i]=true;
				}
				++k;
			}
		}
	}
	for (int i=0;i<101;++i){
		numcow+=patientzero[i];
	}
	cout << numcow << " " << mink << " ";
	if (maxk>=t){
		cout << "Infinity" << endl;
	}
	else cout << maxk << endl;
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
	string name="tracing";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
