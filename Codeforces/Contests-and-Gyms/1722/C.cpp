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
	int n;
	cin >> n;
	vector<vs> s(3,vs(n));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> s[i][j];
		}
	}
	map<str,int> m;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			++m[s[i][j]];
		}
	}
	int ans[3]{};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[s[i][j]] == 1) ans[i] += 3;
			if (m[s[i][j]] == 2) ++ans[i];
		}
	}
	for (const int& res: ans) cout << res << " ";
	cout << endl;
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