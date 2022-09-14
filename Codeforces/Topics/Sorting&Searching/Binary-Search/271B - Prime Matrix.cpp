/**
 *    author:    tachithanhdanh
 *    created:   2022-09-13    10:37:01
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
const int MX = 1e5 + 50;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	// Sieve
	vb isPrime(MX + 1, true);
	vi prime;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2 * 2; i <= MX; i += 2) isPrime[i] = false;
	for (int i = 3; i * i <= MX; i += 2) {
		if (isPrime[i]) {
			for (int j = i * i; j <= MX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	prime.pb(2);
	for (int i = 3; i <= MX; i += 2) if (isPrime[i]) prime.pb(i);
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	for (vi& aa: a) {
		for (int& aaa: aa) {
			cin >> aaa;
		}
	}
	int ans = 2 * MOD;
	int primes = sz(prime);
	auto firstTrue = [&](const int& num) -> int {
		int lo = 0, hi = primes;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (prime[mid] >= num) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	};
	for (int i = 0; i < n; ++i) {
		int moves = 0;
		for (int j = 0; j < m; ++j) {
			int pos = firstTrue(a[i][j]);
			moves += prime[pos] - a[i][j];
		}
		ckmin(ans, moves);
	}
	for (int j = 0; j < m; ++j) {
		int moves = 0;
		for (int i = 0; i < n; ++i) {
			int pos = firstTrue(a[i][j]);
			moves += prime[pos] - a[i][j];
		}
		ckmin(ans, moves);
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