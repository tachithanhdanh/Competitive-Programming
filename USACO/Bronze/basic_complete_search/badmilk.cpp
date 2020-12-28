#include <sstream>
#include <iostream>
#include <fstream>
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
using si = short int;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;

#define ar array
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map

//vector
#define vt vector
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rsz resize
#define pb push_back
#define pf push_front
#define ft front()
#define bk back()
#define ins insert
#define lb lower_bound
#define ub upper_bound

//pairs and tuples
#define f first
#define s second
#define mp make_pair
#define mtp make_tuple

void setIO(string name =""){
//Compile with those flags and to get the fastest performance
//g++.exe -std=c++11 -DLOCAL ${file} -o ${file_base_name}.exe -Wl,--stack,268435456 -O2 && ${file_base_name}.exe
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
	return;
}

//constant initialization
const string yes="YES",no="NO";
const int mod=1e9+7;

//variables used for the current problem
int N,M,D,S,m,p,t,sick[51],possible[51],cnt,ans,badmilk; vt<vt<pair<int,int>>> v;
bool flag,milkflag[51];

void solve(){
	cin >> N >> M >> D >> S;
	v.rsz(N+1);
	for (int i=0;i<D;++i){
		cin >> p >> m >> t;
		v[p].pb(mp(t,m));
	}
	for (int i=1;i<=N;++i){
		sort(all(v[i]));
		//cout << i << endl;
		/*
		for (pair<int,int> pp: v[i]){
			cout << pp.f << " " << pp.s << endl;
		}
		*/
	}
	for (int i=0;i<S;++i){
		cin >> p >> t;
		sick[p]=t;
	}
	for (int i=1;i<=N;++i){
		if (sick[i]){
			for (int j=1;j<=M;++j) milkflag[j]=false;
			for (int j=0;j<sz(v[i]);++j){
				if (v[i][j].f>=sick[i]) break;
				else {
					//cerr << v[i][j].s << endl;
					milkflag[v[i][j].s]=true;
				}
			}
			for (int j=1;j<=M;++j){
				possible[j]+=milkflag[j];
			}
		}
	}
	//cout << yes << endl;
	for (int i=1;i<=M;++i){
		//cout << i << " " << possible[i] << endl;
		if (possible[i]==S) {
			//cout << i << endl;
			badmilk=i; break;
			//cout << i << endl;
		}
	}
	//cout << sz(badmilk) << endl;
	for (int i=1;i<=N;++i){
		if (!sick[i]){
			flag=false;
			for (int j=0;j<sz(v[i]);++j){
				flag = (v[i][j].s == badmilk) || flag;
			}
			//if (flag) cerr << i << endl;
			cnt+=flag;
		}
	}
	ans=max(ans,cnt);
	cout << S+ans << endl;
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
	//string name="diamond";
	setIO("badmilk");
	//cout.tie(NULL);
	/*
	cin >> t;
	for (int i=1;i<=t;++i){
		//cout << "Test " << i << endl; 
		solve();
	}
	*/
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}
