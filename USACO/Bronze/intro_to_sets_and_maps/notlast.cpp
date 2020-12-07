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

int n,milk,sec,cnt; map<string,int> mp; string cow;
string cowlist[]={"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
 
void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<7;++i){
		mp[cowlist[i]]=0;
	}
	while (n--){
		cin >> cow >> milk;
		mp[cow]+=milk;
	}
	milk=1e5;
	for (pair<string,int> p : mp){
		milk=min(milk,p.second);
	}
	sec=1e5;
	for (auto p : mp){
		if (p.second<sec && p.second!=milk){
			sec=p.second;
		}
	}
	if (sec==(int)1e5){
		cout << "Tie" << endl; return;
	}
	for (auto p: mp){
		if (p.second==sec){
			cow=p.first;
			++cnt;
		}
	}
	if (cnt>1) cout << "Tie" << endl;
	else {
		cout << cow;
	}
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
	setIO("notlast");
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
