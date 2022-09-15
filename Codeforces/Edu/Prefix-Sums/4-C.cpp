/**
 *    author:    tachithanhdanh
 *    created:   2022-09-14    11:12:29
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
bool multitest = not true;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vl> b(n + 2, vl(m + 2)), a = b;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] = b[i][j] - b[i - 1][j] - b[i][j - 1] + b[i - 1][j - 1];
		}
	}
	int q;
	cin >> q;
	for (int qq = 1; qq <= q; ++qq) {
		int xL, xR, yL, yR, d;
		cin >> xL >> yL >> xR >> yR >> d;
		a[xL][yL] += d;
		a[xL][yR + 1] -= d;
		a[xR + 1][yL] -= d;
		a[xR + 1][yR + 1] += d;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			cout << a[i][j] << " \n"[j == m];
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