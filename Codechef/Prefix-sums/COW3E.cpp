/**
 *    author:    tachithanhdanh
 *    created:   2022-09-07    10:17:44
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
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
const bool multitest = false;

void solve() {
	// Must use long long
	// consider this test case where n = m = 1000 and all initial elements (init_val) are 1000
	// then there are u = 100000 queries, each query has r1 = c1 = 0 and r2 = c2 = 999 and k = 10000
	// then the prefix sum at r = c = 999 is k * u * n * m * init_val = 10^15
	// huge number, right?
	ll n, m, u, q, ans[1010][1010]{}, a[1010][1010]{}, k, r1, c1, r2, c2;
	cin >> n >> m >> u >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			// 2-D difference array
			ans[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= u; ++i) {
		cin >> k >> r1 >> c1 >> r2 >> c2;
		// Update on 2-D difference array
		++r1, ++c1, ++r2, ++c2;
		ans[r1][c1] += k;
		ans[r2 + 1][c1] -= k;
		ans[r1][c2 + 1] -= k;
		ans[r2 + 1][c2 + 1] += k;
	}
	for (k = 1; k <= 2; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				ans[i][j] += ans[i][j - 1] + ans[i - 1][j] - ans[i - 1][j - 1];
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> r1 >> c1 >> r2 >> c2;
		++r1, ++c1, ++r2, ++c2;
		cout << ans[r2][c2] - ans[r2][c1 - 1] - ans[r1 - 1][c2] + ans[r1 - 1][c1 - 1] << endl;
	}
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