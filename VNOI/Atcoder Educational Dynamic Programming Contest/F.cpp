/**
 *    author:    tachithanhdanh
 *    created:   2022-09-27    19:32:41
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
const bool multitest = true == false;

void solve() {
	str s, t;
	cin >> s >> t;
	int n = sz(s), m = sz(t);
	vector<vi> LCS(n + 1, vi(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else ckmax(LCS[i][j], max(LCS[i - 1][j], LCS[i][j - 1]));
		}
	}
	// db(LCS[n][m]);

	// trace back
	vector<char> ans(LCS[n][m]);
	for (int i = n, j = m, index = LCS[n][m]; i >= 1 && j >= 1;) {
		if (s[i - 1] == t[j - 1]) {
			ans[--index] = s[i - 1];
			--i, --j;
		}
		else if (LCS[i - 1][j] > LCS[i][j - 1]) {
			--i;
		}
		else {
			--j;
		}
	}
	for(const char& c : ans) cout << c;
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
