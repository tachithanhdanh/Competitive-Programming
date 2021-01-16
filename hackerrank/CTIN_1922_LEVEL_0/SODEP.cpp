#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)

void setIO(string name = "") { 
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	else{
		#ifdef LOCAL
		freopen("input.txt", "r", stdin);  
		freopen("output.txt", "w", stdout); 
		freopen("error.txt", "w", stderr);
		#endif 
	}
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7;
const int maxn=1e6+10;
const ll INF = 1e18;

//variables used for the current problem
const int maxnum=1e7+10,maxprime=1000;
bool prime[maxprime]; vector<int> ans(maxn); int n;


void sieve(){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for (int i=2*2;i<maxprime;i+=2) prime[i]=false;
	for (int i=3*3;i<maxprime;i+=3) prime[i]=false;
	for (int i=5;i*i<maxprime;i+=6){
		if (prime[i]){
			for (int j=i*i;j<maxprime;j+=i){
				prime[j]=false;
			}
		}
		if (prime[i+2]){
			for (int j=(i+2)*(i+2);j<maxprime;j+=(i+2)){
				prime[j]=false;
			}
		}	
	}
}

int sum(int num){
	int ans = 0;
	while (num){
		ans+=(num%10)*(num%10);
		num/=10;
	}
	return ans;
}

void init(){
	int pos=0;
	F0R(i,maxnum){
		if (prime[sum(i)]){
			ans[pos]=i; ++pos;
		}
		if (pos>=maxn) return;
	}
}

void solve(){
	sieve();
    init();
    cin >> n;
    cout << ans[n-1];
    return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}