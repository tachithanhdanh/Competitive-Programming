/**
 *    author:    tachithanhdanh
 *    created:   2022-09-13    09:51:30
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
	int n;
	cin >> n;
	vi a(n);
	for (int& aa: a) cin >> aa;
	auto check = [&] (const int& len) -> bool {
		// cout << "len = " << len << " case:" << endl;
		int preOneLen = 0, preTwoLen = 0;
		int curOneLen = 0, curTwoLen = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				if (!curOneLen) {
					preTwoLen = curTwoLen;
					curTwoLen = 0;
				}
				++curOneLen;
				if (preTwoLen >= curOneLen && curOneLen == len) return true;
			}
			else {
				if (!curTwoLen) {
					preOneLen = curOneLen;
					curOneLen = 0;
				}
				++curTwoLen;
				if (preOneLen >= curTwoLen && curTwoLen == len) return true;
			}
			// cout << "pos i = " << i << endl;
			// cout << preOneLen << " " << preTwoLen << endl;
			// cout << curOneLen << " " << curTwoLen << endl;
			// cout << endl;
		}
		// cout << "case len = " << len << " is false" << endl << endl;
		return false;
	};
	int lo = 0, hi = (n / 2) * 2;
	while (lo < hi) { // find last true
		int mid = lo + (hi - lo + 1) / 2;
		if (check(mid)) {
			lo = mid;
		}
		else hi = mid - 1;
	}
	cout << lo * 2 << endl;
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