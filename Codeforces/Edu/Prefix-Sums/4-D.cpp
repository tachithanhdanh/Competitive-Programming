/**
 *    author:    tachithanhdanh
 *    created:   2022-09-15    10:19:11
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
const bool multitest = true;

// https://codeforces.com/blog/entry/88248?#comment-766558
// Oh fuck, too hard to understand :( 
void solve() {
	int n;
	cin >> n;
	vi s(n + 5);
	vi pref(n + 5);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		pref[i] += pref[i - 1];
		ans += max(0, s[i] - 1 - pref[i]);
		if (pref[i] - (s[i] - 1) > 0) { 
			pref[i + 1] += pref[i] - (s[i] - 1);
			pref[i + 2] -= pref[i] - (s[i] - 1);
		}
		if (s[i] > 1) {
			int minPos = min(n, s[i] + i);
			++pref[i + 2];
			--pref[minPos + 1];
		}
	}
	cout << ans << endl;
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