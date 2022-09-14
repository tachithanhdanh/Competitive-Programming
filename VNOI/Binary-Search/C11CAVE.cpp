/**
 *    author:    tachithanhdanh
 *    created:   2022-09-13    13:58:55
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
	int N, H;
	cin >> N >> H;
	vector<vi> h(2, vi(N / 2));
	for (int i = 0; i < N; ++i) {
		cin >> h[i & 1][i / 2];
	}
	sort(all(h[0]));
	sort(all(h[1]));
	auto firstTrue = [&](const int& curHeight, const int& state) -> int { // or std::lower_bound
		int lo  = 0, hi = N / 2;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (h[state][mid] >= curHeight) {
				hi = mid;
			}
			else lo = mid + 1;
		}
		return lo;
	};
	int minObstacles = MX, numberOfWays = 0;
	for (int h0 = 1; h0 <= H; ++h0) {
		int h1 = H - h0 + 1;
		int destroyH0 = N / 2 - firstTrue(h0, 0);
		int destroyH1 = N / 2 - firstTrue(h1, 1);
		int totalDestroyed = destroyH0 + destroyH1;
		if (ckmin(minObstacles, totalDestroyed)) numberOfWays = 1;
		else if (minObstacles == totalDestroyed) ++numberOfWays;
	}
	cout << minObstacles << " " << numberOfWays << endl; 
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