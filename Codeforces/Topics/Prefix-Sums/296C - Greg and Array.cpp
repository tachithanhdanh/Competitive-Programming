/**
 *    author:    tachithanhdanh
 *    created:   2022-09-06    18:58:12
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
const int MX = 1e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

struct OP {
	int l, r, d;
};

void solve() {
	int n, m, k, q[MX]{}, b[MX]{};
	ll a[MX]{};
	OP op[MX];
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		a[i] = ll(b[i] - b[i - 1]);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> op[i].l >> op[i].r >> op[i].d;
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		++q[x], --q[y + 1];
	}
	for (int i = 1; i <= m; ++i) q[i] += q[i - 1];
	for (int i = 1; i <= m; ++i) {
		a[op[i].l] += 1LL * op[i].d * q[i], a[op[i].r + 1] -= 1LL * op[i].d * q[i];
	}
	for (int i = 1; i <= n; ++i) {
		a[i] += a[i - 1];
		cout << a[i] << " ";
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