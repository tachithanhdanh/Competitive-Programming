/**
 *    author:    tachithanhdanh
 *    created:   2022-09-12    17:38:55
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

const str filename = "SEARCH";

void solve() {
	int N;
	cin >> N;
	vi A(N);
	for (int& a: A) cin >> a;
	sort(all(A));
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		int lo = 0, hi = N;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (A[mid] >= k) {
				hi = mid;
			}
			else lo = mid + 1;
		}
		cout << (lo != N && A[lo] == k) << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#else
	freopen((filename + ".INP").c_str(), "r", stdin);
	freopen((filename + ".OUT").c_str(), "w", stdout);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}
