/**
 *    author:    tachithanhdanh
 *    created:   2022-09-06    15:35:30
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
const int MX = 1e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	int N;
	cin >> N;
	int s[MX]{}, minL[MX]{}, minR[MX]{};
	for (int i = 1; i <= N; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}

	// tìm minL giống bài Maximum Subarray Sum của CSES
	// https://cses.fi/paste/bd0543e8c7b6e0c745d0fc/
	for (int i = 1; i <= N; ++i) {
		if (s[i] < s[minL[i - 1]]) minL[i] = i;
		else minL[i] = minL[i - 1];
	}

	// tìm minR thì cũng như vậy nhưng mà theo chiều ngược lại
	minR[N + 1] = N;
	for (int i = N; i >= 1; --i) {
		if (s[i] < s[minR[i + 1]]) minR[i] = i;
		else minR[i] = minR[i + 1];
	}

	int ans{};
	for (int i = 1; i <= N; ++i) {
		bool ok = true;

		// Nếu tổng từ vị trí i đến vị trí có tổng nhỏ nhất từ i đến N <= 0 thì false
		if (s[minR[i]] - s[i - 1] <= 0) ok = false;

		// Nếu tổng từ vị trí i đến N + tổng tiền tố min trong đoạn [1, i - 1] <= 0 thì trả về false
		// gần giống bài CSES Maximum Subarray Sum
		if ((s[N] - s[i - 1]) + s[minL[i - 1]] <= 0) ok = false;
		ans += ok;
	}
	cout << ans;
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
