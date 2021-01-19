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

int n,a[(int)1e3+10],pre; ll ans,sum;

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
		//cerr << a[i] << " ";
	}
	//cerr << endl;
	for (int i=0;i<n;++i){
		pre=a[i]; sum=pre;
		//cerr << pre << " ";
		for (int j=i+1;j<n;++j){
			if (a[j]>pre){
				pre=a[j]; sum+=(ll)pre;
				//cerr << pre << " ";
			}
		}
		cerr << endl;
		ans=max(ans,sum);
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="AWARD";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
