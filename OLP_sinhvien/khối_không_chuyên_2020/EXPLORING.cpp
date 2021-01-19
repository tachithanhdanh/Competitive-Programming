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

#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()){
		freopen((name+".INP").c_str(),"r",stdin);
		freopen((name+".OUT").c_str(),"w",stdout);
	}
	else {
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	}
	return;
}

int n,k,a,sum1,sum,k1,k2; vector<int> neg,pos,neg1,pos1;

void solve(){
	cin >> n >> k;
	for (int i=0;i<n;++i){
		cin >> a;
		if (a>0) pos.push_back(a);
		else neg.push_back(a);
	}
	k1=k; k2=k;
	sort(all(neg)); //sort(rall(pos));
	sort(all(pos),greater<int>());
	neg1=neg; pos1=pos;
	//cerr << pos.size();
	for (int i=0;i<neg.size();++i){
		if (k1){
			--k1; neg[i]=abs(neg[i]);
		}
		else break;
	}
	for (int i=0;i<pos1.size();++i){
		if (k2){
			--k2; pos1[i]=-abs(pos1[i]);
		}
		else break;
	}
	for (auto x : pos){
		sum+=x;
	}
	for (auto x : neg){
		sum+=x;
	} 
	for (auto x : pos1){
		sum1+=x;
	}
	for (auto x : neg1){
		sum1+=x;
	} 
	//cerr << sum << endl << sum1 << endl;
	cout << max(abs(sum1),abs(sum)) << endl;
	return;
}

int main(){
	string name="EXPLORING";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}