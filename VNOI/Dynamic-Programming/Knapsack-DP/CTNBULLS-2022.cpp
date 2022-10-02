/**
 *    author:    tachithanhdanh
 *    created:   2022-10-02    19:38:38
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
using vvi = vector<vi>;
using vvl = vector<vl>;
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
const int MOD = 2111992; // 998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true == false;

void solve() {
	int N, K;
	cin >> N >> K;
	vvi dp(2, vi(N + 1));
	dp[0][0] = dp[1][0] = dp[1][1] = dp[0][1] = 1;
	for (int i = 2; i <= N; ++i) {
		(dp[0][i] = dp[1][i - 1] + dp[0][i - 1]) %= MOD;
		if (i - K >= 1) (dp[1][i] = dp[0][i - K]) %= MOD;
		else dp[1][i] = 1;
	}
	cout << (dp[0][N] + dp[1][N]) % MOD;
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