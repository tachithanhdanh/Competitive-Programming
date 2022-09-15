/**
 *    author:    tachithanhdanh
 *    created:   2022-09-14    14:31:59
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
const ll MOD = 1LL << 32; // 998244353
const int MX = (1 << 24) + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
bool multitest = true == false;

ll c[MX];
int m, q;
ll l, r;

// pseudo-random number generator
unsigned int adding;
unsigned int a, b; // даны во входных данных
unsigned int cur = 0; // беззнаковое 32-битное число
unsigned int nextRand() {
    cur = cur * a + b; // вычисляется с переполнениями
    return cur >> 8; // число от 0 до 2^24 - 1.
}

void solve() {
	cin >> m >> q >> a >> b;
	for (int i = 1; i <= m; ++i) {
		adding = nextRand(); // число, которое нужно прибавить
		l = nextRand();
		r = nextRand();
		++l, ++r;
		if (l > r) swap(l, r); // получили отрезок [l..r]
		c[l] += adding;
		c[r + 1] -= adding;
	}
	for (int i = 1; i <= (1 << 24) + 5; ++i) {
		c[i] += c[i - 1];
	}
	for (int i = 1; i <= (1 << 24) + 5; ++i) {
		(c[i] += c[i - 1]) %= MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= q; ++i) {
		l = nextRand();
		r = nextRand();
		++l;
		++r;
		if (l > r) swap(l, r); // получили отрезок [l..r]
		ans += c[r] - c[l - 1];
	}
	cout << ((ans % MOD) + MOD) % MOD;
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