/**
 *    author:    tachithanhdanh
 *    created:   2022-09-25    14:13:46
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#else
#define db(x) 42
#endif

#define endl "\n"

using ull = unsigned long long;
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
const int MX = 1e7 + 200;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true;

vb isPrime(MX + 1, true);
vi prime(int(6'000'000));
int len;

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= 3; ++i) {
		for (int j = i * i; j <= MX; j += i) isPrime[i] = false;
	}
	for (int i = 5; i * i <= MX; i += 6) {
		int ii = i + 2;
		if (isPrime[i]) for (int j = i * i; j <= MX; j += i) isPrime[j] = false;
		if (isPrime[ii]) for (int j = ii * ii; j <= MX; j += ii) isPrime[j] = false;
	}
	prime[0] = 2; 
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	len = 4;
	for (int i = 11; i + 2 <= MX; i += 6) {
		if (isPrime[i]) prime[len++] = i;
		if (isPrime[i + 2]) prime[len++] = i + 2;
	}
}

void solve() {
	ull n;
	int k;
	cin >> n >> k;
	ull p = 1, mx = 0;
	for (int i = 0; i < k; ++i) p *= prime[i];
	int i = k;
	const long double LOGN = log10l(n);
	do {
		if (p <= n) ckmax(mx, p);
		p /= prime[i - k];
		// This prevents unsigned long long overflow
		if (log10l(p) + log10l(prime[i]) > LOGN) break;
		p *= prime[i];
		++i;
	} while (i < len && p <= n);
	if (mx == 0) cout << -1;
	else cout << mx;
	cout << endl;
	// cout << (mx == 0 ? -1 : mx) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	sieve();
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}