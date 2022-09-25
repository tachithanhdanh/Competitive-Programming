/**
 *    author:    tachithanhdanh
 *    created:   2022-09-25    09:09:49
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
const bool multitest = true;

// Idea: https://codeforces.com/blog/entry/107231?#comment-955465

// Took me 1 hour to debug because of this silly mistake: https://www.diffchecker.com/iyCJIVK3

void solve() {
	int n, k;
	cin >> n >> k;

	vi a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	vl suffix(n + 2), prefix(n + 2);
	for (int x = k - 1; x >= 0; --x) {
		suffix[x] = suffix[x + 1] + a[x]; 
	}
	for (int y = k + 1; y <= n + 1; ++y) {
		prefix[y] = prefix[y - 1] + a[y];
	}

	vi firstX, firstY;
	firstX = firstY = {k};
	for (int x = k - 1; x >= 0; --x) {
		if (suffix[x] - suffix[firstX.back()] > 0) firstX.pb(x); 
	}
	for (int y = k + 1; y <= n + 1; ++y) {
		if (prefix[y] - prefix[firstY.back()] > 0) firstY.pb(y);
	}

	int lenX = sz(firstX), lenY = sz(firstY);
	vl minX(lenX), minY(lenY);
	minX[0] = minY[0] = 0;
	for (int i = 1; i < lenX; ++i) {
		int xFirst = firstX[i - 1], xLast = firstX[i];
		ll minSuffixSum = INF;
		for (int x = xFirst - 1; x >= xLast; --x) {
			ckmin(minSuffixSum, suffix[x] - suffix[xFirst]);
		}
		minX[i] = minSuffixSum;
	}
	for (int i = 1; i < lenY; ++i) {
		int yFirst = firstY[i - 1], yLast = firstY[i];
		ll minPrefixSum = INF;
		for (int y = yFirst + 1; y <= yLast; ++y) {
			ckmin(minPrefixSum, prefix[y] - prefix[yFirst]);
		}
		minY[i] = minPrefixSum;
	}

	vl sumXInterval(lenX), sumYInterval(lenY);
	for (int i = 1; i < lenX; ++i) {
		sumXInterval[i] = suffix[firstX[i]] - suffix[firstX[i - 1]];
	}
	// See this silly mistake I made: https://www.diffchecker.com/iyCJIVK3
	for (int i = 1; i < lenY; ++i) {
		sumYInterval[i] = prefix[firstY[i]] - prefix[firstY[i - 1]];
	}

	ll health = a[k];
	// forgot to handle this case
	if (health < 0) return void(cout << no);
	int X, Y;
	X = Y = k;
	for (int i = 1, j = 1; i < lenX || j < lenY;) {
		bool failX = true, failY = true;

		if (i < lenX && health + minX[i] >= 0) {
			health += sumXInterval[i];
			X = firstX[i];
			++i;
			failX = false;
		}

		if (j < lenY && health + minY[j] >= 0) {
			health += sumYInterval[j];
			Y = firstY[j];
			++j;
			failY = false;
		}

		if (failX && failY) break;
	}

	ll healthToReachLeft = INF;
	for (int x = X - 1; x >= 0; --x) {
		ckmin(healthToReachLeft, suffix[x] - suffix[X]);
	}

	ll healthToReachRight = INF;
	for (int y = Y + 1; y <= n + 1; ++y) {
		ckmin(healthToReachRight, prefix[y] - prefix[Y]);
	}

	if (health + healthToReachLeft >= 0 || health + healthToReachRight >= 0) cout << yes;
	else cout << no;
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