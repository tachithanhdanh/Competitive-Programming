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
const int maxn=2e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N; string s, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	string n,m;
	cin >> n;
	if (n=="6174") { cout << 1; return 0; }
	sort(all(n)); m = n; reverse(all(m));
	int cnt = 1;
	int d;
	do {
		++cnt;
		d = stoi(m)-stoi(n);
		while (d<1000) d *= 10;
		n = to_string(d);
		sort(all(n)); m=n; reverse(all(m));
	} while (d!=6174);
	cout << cnt;
	return 0;
}
//https://en.wikipedia.org/wiki/6174_(number)
