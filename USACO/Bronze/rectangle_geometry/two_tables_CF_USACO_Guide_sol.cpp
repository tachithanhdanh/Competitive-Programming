/**
*    author:    tachithanhdanh
*    created:    2022-09-03    16:45:21
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

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

void solve() {
	// Solution from USACO Guide.
	int W, H, x1, y1, x2, y2, w, h;
	cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
	int ans{MOD};
	if (x2 + max(0, w - x1) <= W) ckmin(ans, max(0, w - x1));
	if (x1 - max(0, x2 - (W - w)) >= 0) ckmin(ans , max(0, x2 - (W - w)));
	if (y2 + max(0, h - y1) <= H) ckmin(ans, max(0, h - y1));
	if (y1 - max(0, y2 - (H - h)) >= 0) ckmin(ans , max(0, y2 - (H - h)));
	cout << (ans == MOD? -1 : ans) << endl;
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