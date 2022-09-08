/**
 *    author:    tachithanhdanh
 *    created:   2022-09-08    08:35:37
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
const int MOD = 998244353;
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	int n, k;
	cin >> n >> k;
	vpi segs(k);
	for (pi& seg: segs) cin >> seg.f >> seg.s;
	vl dp(n + 2);
	// create difference array at first
	dp[1] = 1;
	dp[2] = -1;
	for (int i = 1; i <= n; ++i) {
		// update on the way it goes to obtain the real dp array
		(dp[i] += dp[i - 1]) %= MOD;
		for (const auto& [l, r]: segs) {
			if (i + l <= n) {
				(dp[i + l] += dp[i]) %= MOD;
			}
			if (i + r <= n) {
				// https://math.stackexchange.com/questions/2179579/how-can-i-find-a-mod-with-negative-number
				// in case there are negative numbers
				((dp[i + r + 1] -= dp[i]) += MOD) %= MOD;
			}
		}
	}
	cout << dp[n] % MOD;
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