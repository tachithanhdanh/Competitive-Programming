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
ll N;
vector<pi> factors;
int cnt;

ll fastpow(ll x, int y) {
	ll res = 1;
	while (y) {
		if (y&1) res *= x;
		y>>=1;
		x*=x;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> N;

	//Prime factorization
	if (!(N&1)) {
		while (!(N&1)) N >>= 1, ++cnt;
		factors.pb(mp(2,cnt));
	}
	if (N % 3 == 0) {
		cnt = 0;
		while (N % 3 == 0) N /= 3, ++cnt;
		factors.pb(mp(3,cnt));
	}
	for (int i = 5, t = 2; i * i <= N; i += 2, t = 6 - t) {
		if (N % i == 0) {
			cnt = 0;
			while (N % i == 0) N /= i, ++cnt;
			factors.pb(mp(i,cnt));
		}
	}
	if (N != 1) factors.pb(mp(N,1));
	N /= N;
	each(factor,factors) N *= fastpow((ll)factor.f, factor.s&1);
	cout << N;
	return 0;
}
