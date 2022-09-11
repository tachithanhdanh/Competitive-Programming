/**
 *    author:    tachithanhdanh
 *    created:   2022-09-10    17:40:31
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
	int N, L, U;
	cin >> N >> L >> U;
	vi X(N);
	for (int& x: X) cin >> x;
	// coordinate compression
	vi compressed = X;
	sort(all(compressed));
	compressed.erase(unique(all(compressed)), end(compressed));
	function<int(const int&)> pos = [&] (const int& num) -> int {
		return int(lower_bound(all(compressed), num) - begin(compressed));
	};
	function<ll(const int&)> countSubarrays = [&] (const int& numDif)-> ll {
		vi cnt(sz(compressed));
		int curNumDif = 0;
		ll counts = 0;
		for (int l = 0, r = 0; r < N; ++r) {
			curNumDif += ++cnt[pos(X[r])] == 1;
			while (l <= r && curNumDif > numDif) {
				curNumDif -= --cnt[pos(X[l++])] == 0;
			}
			counts += r - l + 1;
		}
		return counts;
	};
	ll countLessThanL = countSubarrays(L - 1);
	ll countNotGreaterThanU = countSubarrays(U);
	cout << countNotGreaterThanU - countLessThanL;
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
