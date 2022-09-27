/**
 *    author:    tachithanhdanh
 *    created:   2022-09-27    18:39:03
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
const int MX = 1e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true == false;

struct item {
	int w, val;
	item(int ww = 0, int vv = 0): w(ww), val(vv) { }
};

void solve() {
	int N, W;
	cin >> N >> W;
	// dp[N][V] = min(dp[N - 1][V], dp[N - 1][V - val[N]] + w[N])
	vector<item> items(N + 1);
	for (int i = 1; i <= N; ++i) {
		int w, val;
		cin >> w >> val;
		items[i] = item(w, val);
	}
	vector<vl> dp(N + 1, vl(MX + 1, INF));
	dp[0][0] = 0;
	for (int n = 1; n <= N; ++n) {
		for (int v = 0; v <= MX; ++v) {
			dp[n][v] = dp[n - 1][v];
			if (v - items[n].val >= 0) ckmin(dp[n][v], dp[n - 1][v - items[n].val] + items[n].w);
		}
	}
	for (int val = MX; val >= 0; --val) {
		if (dp[N][val] <= W) {
			cout << val << endl;
			return;
		}
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
