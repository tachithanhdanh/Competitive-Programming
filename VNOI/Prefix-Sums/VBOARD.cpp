/**
 *    author:    tachithanhdanh
 *    created:   2022-09-07    09:44:44
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
	int n, q, pref[2][505][505]{};
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> pref[(i + j) & 1][i][j];
		}
	}
	for (int k = 0; k < 2; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				pref[k][i][j] += pref[k][i - 1][j] + pref[k][i][j - 1] - pref[k][i - 1][j - 1];
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		int black = pref[0][i2][j2] - pref[0][i2][j1 - 1] - pref[0][i1 - 1][j2] + pref[0][i1 - 1][j1 - 1];
		int white = pref[1][i2][j2] - pref[1][i2][j1 - 1] - pref[1][i1 - 1][j2] + pref[1][i1 - 1][j1 - 1];
		cout << abs(black - white) << endl;
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
