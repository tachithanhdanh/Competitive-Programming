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
const int maxn=1e3+10;
const ll INF = 1e18;

//variables used for the current problem
string a,b; vi num; bool flag[3]; int c,d;

int binary(const string &a){
	int ans = 0;
	F0R(i,sz(a)){
		ans+=(int(a[i]-'0') << i);
	}
	return ans;
}

int pow3(const int &n,const int &p){
	int ans = 1;
	F0R(i,p) ans*=3;
	return n*ans;
}

int ternary(const string &b){
	int ans = 0;
	F0R(i,sz(b)){
		ans+=pow3(int(b[i]-'0'),i);
	}
	return ans;
}

void solve(){
	cin >> a >> b;
	reverse(all(a)); reverse(all(b));
	c=binary(a); d=ternary(b);
	F0R(i,sz(a)){
		a[i]= (a[i]=='0' ? '1' : '0');
		num.pb(binary(a));
		a[i]= (a[i]=='0' ? '1' : '0');
	}
	sort(all(num));
	F0R(i,sz(b)){
		char f; f=b[i];
		memset(flag,false,sizeof(flag));
		flag[b[i]-'0']=true;
		F0R(j,3){
			if (!flag[j]){
				b[i]=char(j+'0');
			}
			if (binary_search(all(num),ternary(b)) && ternary(b)!=c && ternary(b)!=d) {
				cout << ternary(b); return;
			}
		}
		b[i]=f;
	}
	return;
}

int main() {
	setIO();
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl;
	return 0;
}