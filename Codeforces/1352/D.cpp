#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD=1e9+7; //998244353
const ll INF = 1e18; //Not too close to LLONG_MAX

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vi a(N); each(b,a) cin >> b;
		int i = 0, j = N - 1;
		int moves = 0, A = 0, B = 0;
		int sum, pre = 0;
		while (i<=j) {
			sum = 0;
			while (sum <= pre) {
				if (moves&1) {
					sum += a[j]; --j;
				}
				else {
				sum += a[i]; ++i;
				}
				if (i>j) break;
			}
			if (moves&1) B += sum;
			else A += sum;
			++moves;
			if (i>j || sum <= pre) break;
			pre = sum;
		}
		cout << moves << " " << A << " " << B << endl;
	}
	return 0;
}
