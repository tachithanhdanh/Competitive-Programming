#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
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
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
vector<string> bit; string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	while (cin >> s) {
		bit.pb(s);
	}
	
	//Horizontal bit strings case
	F0R(i,sz(bit)) s = max(s, bit[i]);

	string temp; temp.rsz(sz(bit));

	//Vertical bit strings case
	F0R(i,sz(bit)) {
		F0R(j,sz(bit)) temp[j] = bit[j][i];
		s = max(s, temp);
	}

	//Main diagonal case
	F0R(i,sz(bit)) temp[i] = bit[i][i]; 
	s = max(s, temp);
	R0F(i,sz(bit)) temp[sz(bit)-1-i] = bit[i][i]; 
	s = max(s, temp);

	//Antidiagonal case
	F0R(i,sz(bit)) temp[i] = bit[sz(bit)-1-i][i];
	s = max(s, temp);
	R0F(i,sz(bit)) temp[sz(bit)-1-i] = bit[sz(bit)-1-i][i];
	s = max(s, temp);

	cout << s;
	return 0;
}
