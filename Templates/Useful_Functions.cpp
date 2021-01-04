#include <bits/stdc++.h>
 
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
const ll maxn=1e7+10;

//variables used for the current problem
int n; ll x,m; bool prime[maxn];


ll sqrt(ll n){
	ll m=sqrt((double)n);
	for (ll i=m-2;i<=m+2;++i){
		if (i*i==n) return i;
	}
	return -1;
}

void sieve(){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for (int i=2*2;i<maxn;i+=2) prime[i]=false;
	for (int i=3*3;i<maxn;i+=3) prime[i]=false;
	for (int i=2*2;i<maxn;i+=2) prime[i]=false;
	for (int i=5*5;i<maxn;i+=5) prime[i]=false;
	for (int i=7*7;i<maxn;i+=7) prime[i]=false;
	for (int i=11*11;i<maxn;i+=11) prime[i]=false;
	for (int i=13*13;i<maxn;i+=13) prime[i]=false;
	for (int i=17*17;i<maxn;i+=17) prime[i]=false;
	for (int i=19*19;i<maxn;i+=19) prime[i]=false;
	for (int i=23;i*i<maxn;i+=2){
		if (prime[i]){
			for (int j=i*i;j<maxn;j+=i){
				prime[j]=false;
			}
		}
	}
}

ll fast_pow(ll x,uint y) 
{ 
    ll res = 1; // Initialize result 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res * x; 
  
        // n must be even now 
        y = y >> 1; // y = y/2 
        x = x * x; // Change x to x^2 
    } 
    return res; 
} 
