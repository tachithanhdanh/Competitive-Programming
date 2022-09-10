
     author    tachithanhdanh
     created   2022-09-10    183603


#include bitsstdc++.h  see generalrunning-code-locally
using namespace std;

#ifdef LOCAL
#include debugging.h
#endif

#define endl n

using ll = long long;
using str = string;

 vectors
using vi = vectorint;
using vl = vectorll;
using vb = vectorbool;
using vs = vectorstr;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back

 pairs
using pi = pairint, int;
using vpi = vectorpi;
#define f first
#define s second
#define mp make_pair

 set min-max value.
templatetypename T bool ckmin(T& a, const T& b) { return b  a  a = b, 1  0; }  set a = min(a,b)
templatetypename T bool ckmax(T& a, const T& b) { return b  a  a = b, 1  0; }  set a = max(a,b)

 constant initialization
const str yes=YESn, no=NOn;
const int MOD = 1e9 + 7;  998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};  for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = false;

void solve() {
	int N, L, U;
	cin  N  L  U;
	vi X(N + 1);
	vpi pairs(N + 1);
	for (int i = 1; i = N; ++i) {
		cin  X[i];
		pairs[i].f = X[i];
		pairs[i].s = i;
	}
	sort(all(pairs));
	vi compressed(N + 1);
	int index = 0;
	for (int i = 1; i = N; ++i) {
		if (pairs[i].f != pairs[i - 1].f) ++index;
		compressed[pairs[i].s] = index;
	}
	functionll(const int&) countSubarrays = [&] (const int& numDif)- ll {
		vi cnt(index + 1);
		int curNumDif = 0;
		ll counts = 0;
		for (int l = 1, r = 1; r = N; ++r) {
			curNumDif += ++cnt[compressed[r]] == 1;
			while (curNumDif  numDif) {
				curNumDif -= --cnt[compressed[l++]] == 0;
			}
			counts += r - l + 1;
		}
		return counts;
	};
	ll countLessThanL = countSubarrays(L - 1);
	ll countNotGreaterThanU = countSubarrays(U);
	cout  countNotGreaterThanU - countLessThanL;
}

int main() {
	cin.tie(0)-sync_with_stdio(0);  see generalfast-io
	#ifdef LOCAL
	freopen(input.txt, r, stdin);
	#endif  LOCAL
	int tt = 1;
	if (multitest) cin  tt;
	for (int t = 0; t  tt; ++t) {
		solve();
	}
	return 0;
}