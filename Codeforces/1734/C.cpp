/**
 *    author:    tachithanhdanh
 *    created:   2022-09-23    19:36:03
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#else
#define db(x) 42
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
const int MX = 1e6 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true;

// vb isPrime(MX + 1, true); 
// vi prime;
// vb marked;
// int num;

// void sieve() {
// 	isPrime[0] = isPrime[1] = false;
// 	for (int i = 4; i <= MX; i += 2) isPrime[i] = false;
// 	for (int i = 3; i * i <= MX; i += 2) {
// 		if (isPrime[i]) {
// 			for (int j = i * i; j <= MX; j += i) {
// 				isPrime[j] = false;
// 			}
// 		}
// 	}
// 	prime.pb(1);
// 	prime.pb(2);
// 	for (int i = 3; i <= MX; i += 2) if (isPrime[i]) prime.pb(i);
// 	num = sz(prime);
// 	marked.resize(num, false);
// 	return;
// }

void solve() {
	int n;
	cin >> n;
	str s;
	cin >> s;
	vi marked(n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] == '0') {
			if (marked[i] == 0) marked[i] = i;
			for (int j = i * 2; j <= n; j += i) {
				if (s[j - 1] == '1') break;
				if (marked[j] == 0) marked[j] = i;
			}
		}
		if (s[i - 1] == '0') {
			ans += marked[i];
		}
	}
	// db(marked);
	cout << ans << endl;
	// ll ans = 0;
	// fill(all(marked), false);
	// for (int i = 1; i <= n; ++i) {
	// 	if (s[i - 1] == '0') {
	// 		if (isPrime[i]) {
	// 			ans += i;
	// 		} else {
	// 			for (int j = 0; j < num; ++j) {
	// 				if (i % prime[j] == 0) {
	// 					ans += prime[j];
	// 					break;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	else 
	// }
	// cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	// sieve();
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}