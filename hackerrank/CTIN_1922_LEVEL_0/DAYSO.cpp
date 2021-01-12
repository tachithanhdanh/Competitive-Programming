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
const int mod=1e9+7;
const int maxn=2e5+10;

//variables used for the current problem
int n,a; bool prime[maxn]; vi ans[3];

void sieve(){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for (int i=2*2;i<maxn;i+=2) prime[i]=false;
	for (int i=3*3;i<maxn;i+=3) prime[i]=false;
	for (int i=5;i*i<=maxn;i+=6){
		if (prime[i]) for (int j=i*i;j<maxn;j+=i) prime[j]=false;
		if (prime[i+2]) for (int j=(i+2)*(i+2);j<maxn;j+=(i+2)) prime[j]=false;
	}
	return;
}

int sqrt(const int &n){
	if (n==1 || !n) return n;
	int m = sqrt(double(n));
	for (int i=m-2;i<=m+2;++i){
		if (i*i==n) return i;
	}
	return -1;
}

bool perfect_num(const int &n){
	int sum=0;
	for (int i=1;i*i<=n;++i){
		if (n%i==0){
			sum+=i;
			if (i*i!=n) sum+=(n/i);
		}
	}
	return 2*n==sum;
}

void solve(){
	cin >> n;
	sieve();
	//cout << sqrt(1) << endl;
	F0R(i,n){
		cin >> a;
		if (prime[a]) ans[0].pb(a);
		if (perfect_num(a)) ans[1].pb(a);
		if (sqrt(a)!=-1) ans[2].pb(a);
	}
	trav(i,ans){
		trav(j,i) cout << j << " ";
		cout << endl; 
	}
	return;
}

int main() {
	setIO();
	solve();
	return 0;
}