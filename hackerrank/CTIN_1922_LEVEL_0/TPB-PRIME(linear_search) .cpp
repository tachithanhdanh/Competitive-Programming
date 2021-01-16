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
const int maxn=5e5+10;
const ll INF = 1e18;

//variables used for the current problem
int n,p; 
vector<bool> check(maxn,true);
vi prime;

void sieve(){
    check[0]=check[1]=false;
    for (int i=2*2;i<maxn;i+=2) check[i]=false;
    for (int i=3*3;i<maxn;i+=3) check[i]=false;
    for (int i=5;i*i<maxn;i+=6){
        if (check[i]){
            for (int j=i*i;j<maxn;j+=i){
                check[j]=false;
            }
        }
        if (check[i+2]){
            for (int j=(i+2)*(i+2);j<maxn;j+=(i+2)){
                check[j]=false;
            }
        }
    }
    int pos=1;
    F0R(i,maxn) if (check[i]) {
        prime.pb(i);
    }
}

void solve(){
	cin >> n;
	sieve();
	while (n--){
        cin >> p;
        int pos = 1;
        trav(a,prime){
        	if (a==p){
        		cout << pos << endl; break;
        	}
        	pos+=log10(a)+1;
        }
	}
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}