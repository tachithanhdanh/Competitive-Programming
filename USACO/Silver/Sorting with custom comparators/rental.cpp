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

const int maxN=1e5+10;
int N,M,R,c[maxN],r[maxN],q,p,pos1,pos2,n,milk,gallons; ll ans,res; 
vector<pair<int,int>> stores,qp;

bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
	return p1.f>p2.f;
}

void solve(){
	cin >> N >> M >> R;
	for (int i=0;i<N;++i){
		cin >> c[i];
	}
	for (int i=0;i<M;++i){
		cin >> q >> p;
		stores.pb(mp(p,q));
	}
	for (int i=0;i<R;++i){
		cin >> r[i];
	}
	sort(c,c+N,greater<int>());
	sort(r,r+R,greater<int>());
	sort(all(stores),comp);
	//cerr << c[0] << endl;
	/*
	for (int i=1;i<N;++i){
		//cerr << c[i] << endl;
		c[i]+=c[i-1];
	}
	for (int i=1;i<=R;++i){
		r[i]+=r[i-1];
	}
	*/
	//cerr << r[0] << endl;
	int iStore=0,iRent=0,i=0;
	while(i<N){
		int litres=c[i];
		int moneyT=0,curI=iStore;
		int last=0;
		while (curI<M){
			int rest=min(stores[curI].s,litres);
			moneyT+=stores[curI].f*rest;
			litres-=rest;
			if (litres==0){
				last=rest;
				break;
			}
			else{
				++curI;
			}
		}
		if (iRent>=R || moneyT>r[iRent]){
			ans+=moneyT;
			iStore=curI;
			if (iStore<M) stores[iStore].s-=last;
			++i;
		}
		else{
			ans+=r[iRent]; ++iRent; --N;
		}
		/*
		pos1=pos2=res=0; n=N;
		qp=stores; pos1=min(i,R); 
		if (pos1) res+=r[pos1-1];
		//if (i==3) cerr << res << endl; 
		n-=pos1; 
		/*
		if (i==3) {
			cerr << n << endl;
			cerr << c[N-1-pos1] << endl;
		}
		
		pos2=min(n,M); milk=c[N-1-pos1];
		for (int j=0;j<pos2;++j){
			//if (i==3) cerr << qp[j].f << endl;
			gallons=min(milk,qp[j].s);
			res+=qp[j].f*gallons;
			//if (i==3) cerr << res << endl;
			milk-=gallons;
			if (milk==0) break;
		}
		//cerr << res << endl;
		ans=max(res,ans);
		*/
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
	string name="rental";
	//string name="";
	setIO(name);
	//cout.tie(NULL);
	//generate();
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}