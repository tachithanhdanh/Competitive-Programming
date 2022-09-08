/**
 *    author:    tachithanhdanh
 *    created:   2022-09-08    09:53:27
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
// https://codeforces.com/blog/entry/84164
// https://codeforces.com/blog/entry/86420
void solve() {
	int N;
	ll C;
	cin >> N >> C;
	int a[MX]{}, b[MX]{}, c[MX]{};

	// coordinate compression using a map
	// store necessary events in map and then re-index it from 0 to N - 1 
	// (just like sorting unique events increasingly)
	map<int, int> m; 
	for (int i = 1; i <= N; ++i) {
		cin >> a[i] >> b[i] >> c[i];
		m[a[i]] = 1;
		m[b[i] + 1] = 1;
	}

	// mảng này lưu ngày của event thứ i
	int event_on_day[MX * 2]{};

	int index = 0;
	for (pair<const int, int>& p: m) {
		p.s = ++index;
		event_on_day[index] = p.f;
	}

	// cost[i] là số tiền phải trả vào sự kiện thứ i (sau khi nén tọa độ của ngày)
	// đầu tiên khởi tạo cost[i] với vai trò là mảng hiệu để dùng trick +1 -1 
	// sau đó tính prefix sum trên đó để khôi phục lại giá trị của cost[i] 
	ll cost[MX * 2]{}; 


	for (int i = 1; i <= N; ++i) {
		cost[m[a[i]]] += c[i];
		cost[m[b[i] + 1]] -= c[i];
	}
	
	ll ans = 0;
	for (int i = 1; i <= index; ++i) {
		cost[i] += cost[i - 1];
		ans += min(C, cost[i]) * (event_on_day[i + 1] - event_on_day[i]);
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