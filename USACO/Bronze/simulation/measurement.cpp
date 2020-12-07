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
 
vector<pair<string,int>> cows;
vector<string> cow_name= {"Bessie", "Elsie", "Mildred"};
vector<tuple<int,string,int>> data;
int ans,n,day,milk; string name; char ch;
vector<string> top,pretop;
string cow;

void solve(){ //Your solution starts here.
	for (int i=0;i<3;++i){
		cows.push_back(make_pair(cow_name[i],7));
	}
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> day >> name >> ch >> milk;
		if (ch=='-') milk-=2*milk;
		data.push_back(make_tuple(day,name,milk));
	}
	sort(data.begin(),data.end());
	/*for (auto x : data){
		cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << " " << endl;
	} */
	top=cow_name;
	for (auto x :data){
		cow=get<1>(x);
		milk=-1;
		pretop=top; top.clear();
		for (int i=0;i<3;++i){
			if (cows[i].first==cow){
				cows[i].second+=get<2>(x);
			}
		}
		for (int i=0;i<3;++i){
			if (cows[i].second>milk){
				milk=cows[i].second;
			}
		}
		for (int i=0;i<3;++i){
			if (cows[i].second==milk){
				top.push_back(cows[i].first);
			}
		}
		/*cerr << "top " << endl;
		for (auto a : top){
			cerr << a << endl;
		}
		cerr << "pretop " << endl;
		for (auto a : pretop){
			cerr << a << endl;
		} */
		if (top!=pretop) ++ans;
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
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
 
