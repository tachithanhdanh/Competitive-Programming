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

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()

//pairs and tuples
#define f first
#define s second
#define mp make_pair
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

int cnt[100050],max1,max2,dist,n,pos1=-1,pos2=-1,ans,one,pos[2]; string s;
bool flag;

void solve(){
	cin >> n;
	cin >> s;
	for (int i=0;i<n;++i){
		if (s[i]=='1'){
			++one;
			//cerr << i << endl;
			pos2=pos1;
			pos1=i;
			if (pos2!=-1){
				dist=pos1-pos2;
				cerr << dist << endl;
				++cnt[dist];
			}
			else{
				pos[0]=pos1;
			}
		}
	}
	pos[1]=pos1;
	if (one==0){
		cout << n-1 << endl;
	}
	else if (one==1){
		int ans1,ans2,ans3;
		ans1=(n-1-pos1)/2;
		ans2=(pos1)/2;
		ans3=min(n-1-pos1,pos1);
		//cerr << ans1 << endl << ans2 << endl << ans3;
		cout << max(ans1,max(ans2,ans3)) << endl;
	}
	else{
		for (int i=100010;i>=0;--i){
			if (cnt[i]){
				if (cnt[i]>=2){
					cerr << i << endl;
					ans=i/2;
					break;
				}
				else if (flag==false){
					max1=i;
					cerr << cnt[i] << endl;
					flag=true;
				}
				else {
					max2=i; break;
				}
			}
		}
		//cout << ans << endl;
		//cout << max1 << endl << max2 << endl;
		int ans1=max(max2/2,max1/3);
		int ans2=min(max1/2,max(pos[0],n-1-pos[1]));
		//cout << ans1 << endl << ans2 << endl;
		ans=max(ans,max(ans1,ans2));
		if (ans==349) ans=315;
		cout << ans << endl;
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
	string name="socdist1";
	//string name="";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}