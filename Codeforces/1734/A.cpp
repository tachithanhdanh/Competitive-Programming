/**
 *    author:    tachithanhdanh
 *    created:   2022-09-23    19:06:57
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#else
#define db(x) 42
#endif

#define endl "\n"

using ll = long long;
using str = string;

// vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back

// pairs
using pi = pair<int, int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

// set min-max value.
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

// constant initialization
const str yes="YES\n", no="NO\n";
const int MOD = 1e9 + 7; // 998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true;

void solve() {
	int n;
	cin >> n;
	vl a(n);
	for (ll& aa : a) cin >> aa;
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				ll median = (a[i] + a[j] + a[k]) / 3;
				// cout << median << endl;
				ll cur[4];
				cur[0] = 0LL + abs(median - a[i]) + abs(median - a[j]) + abs(median - a[k]);
				cur[1] = abs(a[i] - a[k]) + abs(a[i] - a[j]);
				cur[2] = abs(a[j] - a[k]) + abs(a[i] - a[j]);
				cur[3] = abs(a[i] - a[k]) + abs(a[k] - a[j]);
				for (int p = 0; p < 4; ++p) ckmin(ans, cur[p]);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}