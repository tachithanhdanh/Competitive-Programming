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
constexpr int MX = 100'000'500;
constexpr ssize_t N = 5'800'000;

vb isPrime(MX + 1, true);
vi prime(N);
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

void solve(int x) {
	if (!x) return;
	// Find Upper bound of x in prime array (lower bound for x + 1)
	int lo = 0, hi = len;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (prime[mid] >= x + 1) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	int piOfX = lo;
	double piOfX_ld = double(x) / log(x);
	cout << fixed << setprecision(1) << 100.0 * abs((double)piOfX - piOfX_ld) / (double)piOfX << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	sieve();
	int x;
	do {
		cin >> x;
		solve(x);
	} while (x);
	return 0;
}