/**
 *    author:    tachithanhdanh
 *    created:   2022-09-07    09:13:00
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

void solve() {
	int n;
	cin >> n;
	int c[35][35][35]{};
	for (int k = 1; k <= n; ++k) {
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= n; ++i) {
				cin >> c[k][j][i];
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= n; ++i) {
				c[k][j][i] += c[k - 1][j][i] + c[k][j - 1][i] + c[k][j][i - 1] 
							- c[k - 1][j - 1][i] - c[k - 1][j][i - 1] - c[k][j - 1][i - 1] + c[k - 1][j - 1][i - 1];
			}
		}
	}
	int ans{-MOD};
	for (int k = 1; k <= n; ++k) {
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= n; ++i) {
				for (int l = 1; l <= min({i, j, k}); ++l) { 
					// Khối lập phương nên phải đảm bảo dài rộng cao bằng nhau
					int ii = i - l + 1;
					int jj = j - l + 1;
					int kk = k - l + 1;
					int sum = c[k][j][i] - c[kk - 1][j][i] - c[k][jj - 1][i] - c[k][j][ii - 1] 
						+ c[kk - 1][jj - 1][i] + c[kk - 1][j][ii - 1] + c[k][jj - 1][ii - 1] - c[kk - 1][jj - 1][ii - 1];
					ckmax(ans, sum);
				}
			}
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
