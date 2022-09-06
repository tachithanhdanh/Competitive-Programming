/**
 *    author:    tachithanhdanh
 *    created:   2022-09-06    19:46:55
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
const int MX = 1e6 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	int n, q;
	ll a[MX]{}, b[MX]{};
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r, d;
		cin >> l >> r >> d;
		a[l] += d, a[r + 1] -= ll(d) * (r - l + 2), a[r + 2] += ll(d) * (r - l + 1);
	}
	for (int i = 2; i <= n; ++i) {
		a[i] += a[i - 1] + (a[i - 1] - a[i - 2]);
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	for (int i = 1; i <= n; ++i) cout << a[i] + b[i] << " ";
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
// You have to join this group in order to view the contest: https://codeforces.com/group/1rv4rhCsHp/
// Problem link: https://codeforces.com/group/1rv4rhCsHp/contest/319055/problem/E?locale=en