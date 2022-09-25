
     author    tachithanhdanh
     created   2022-09-23    192633


#include bitsstdc++.h  see generalrunning-code-locally
using namespace std;

#ifdef LOCAL
#include debugging.h
#else
#define db(x) 42
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
const bool multitest = true;

void solve() {
	int n;
	cin  n;
	if (n = 1) cout  1  endl;
	if (n = 2) cout  1 1n;
	if (n = 3) {
		for (int i = 3; i = n; ++i) {
			for (int j = 1; j = i; ++j) {
				if (j == 1) cout  1;
				else {
					cout  ' '  01[j == i];
				}
			}
			cout  endl;
		}
	}
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