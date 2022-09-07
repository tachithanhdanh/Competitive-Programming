/**
 *    author:    tachithanhdanh
 *    created:   2022-09-07    14:15:34
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
const int MX = 5e3 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	// must use long long because 
	// in the worse case (n = m = 5000, k = 200000, x = y = 1, X = Y = 5000)
	// pref[5000][5000] will be 5 * 10^11
	ll pref[MX][MX]{};
	for (int i = 0; i < k; ++i) {
		int x, y, X, Y;
		cin >> x >> y >> X >> Y;
		++pref[x][y];
		--pref[X + 1][y];
		--pref[x][Y + 1];
		++pref[X + 1][Y + 1];
	}
	for (k = 0; k < 2; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
			}
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << pref[c][d] - pref[c][b - 1] - pref[a - 1][d] + pref[a - 1][b - 1] << endl;
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