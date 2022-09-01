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

void solve() {
	int n, q;
	cin >> n >> q;
	vi cntH(1001);
	vector<vi> cntW(1001,vi(1));
	for (int i = 0; i < n; ++i) {
		int h, w;
		cin >> h >> w;
		++cntH[h];
		cntW[h].pb(w);
	}
	vector<vi> pref(1001);
	for (int i = 1; i <= 1000; ++i) {
		const int s = sz(cntW[i]);
		sort(all(cntW[i]));
		pref[i].resize(s);
		for (int j = 1; j < s; ++j) pref[i][j] += pref[i][j-1]+cntW[i][j];
	}
	for (int j = 0; j < q; ++j) {
		int h[2], w[2];
		cin >> h[0] >> w[0] >> h[1] >> w[1];
		ll ans{};
		for (int i = h[0]+1; i < h[1]; ++i) {
			auto it1 = upper_bound(all(cntW[i]),w[0]);
			auto it2 = lower_bound(all(cntW[i]),w[1]);
			if (it1 == end(cntW[i]) || it2 == begin(cntW[i])) continue;
			--it2;
			int pos1 = int(it1 - begin(cntW[i]));
			int pos2 = int(it2 - begin(cntW[i]));
			if (pos2 >= pos1) {
				ans += 1LL*i*(pref[i][pos2]-pref[i][pos1-1]);
			}
		}
		cout << ans << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}