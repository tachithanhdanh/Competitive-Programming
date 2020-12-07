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

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	}
	return;
}

int cnt1[101],cnt2[101],a,f=1000,s=1000,ans; bool cnt[10001];

void dfs(int k){
	if (k==5){
		cnt[f]=true;
		return;
	}
	for (int i=0;i<101;++i){
		if (k&1){
			if (cnt1[i]){
				--cnt1[i]; ++cnt2[i];
				s+=i; f-=i;
				dfs(k+1);
				++cnt1[i]; --cnt2[i];
				s-=i; f+=i;
			}
		}
		else {
			if (cnt2[i]){
				--cnt2[i]; ++cnt1[i];
				s-=i; f+=i;
				dfs(k+1);
				++cnt2[i]; --cnt1[i];
				s+=i; f-=i;
			}
		}
	}
}

void solve(){
	for (int i=0;i<10;++i){
		cin >> a; ++cnt1[a];
		//cerr <<a << " ";
	}
	//cerr << endl;
	for (int i=0;i<10;++i){
		cin >> a; ++cnt2[a];
		//cerr <<a <<  " ";
	}
	//cerr << endl;
	dfs(1);
	for (int i=0;i<10001;++i){
		ans+=cnt[i];
		if (cnt[i]) cerr << i << endl;
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="backforth";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}