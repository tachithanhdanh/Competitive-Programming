/**
 *    author:    tachithanhdanh
 *    created:   2022-09-08    09:15:18
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
	int N, M;
	cin >> N >> M;
	char C[1010][1010]{};
	int A[1010][1010]{};
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> C[i][j];
			A[i][j] = C[i][j] - C[i - 1][j] - C[i][j - 1] + C[i - 1][j - 1];
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		++A[X1][Y1];
		--A[X2 + 1][Y1];
		--A[X1][Y2 + 1];
		++A[X2 + 1][Y2 + 1];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
			cout << ((A[i][j] % 2) + 2) % 2;
		}
		cout << endl;
	}
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