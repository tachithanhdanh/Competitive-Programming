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
const ll maxn=1e7+10;

int max_counts; ll ans, N; vi d;

void dfs(int k, int pre_cnt, int counts, ll n) {
	if (n>N) return;
	if (k==12) {
		if (counts > max_counts) {
			ans = n; max_counts = counts;
		}
		else if (counts == max_counts && n < ans) ans = n;
		return;
	}
	counts *= pre_cnt;
	int i;
	for (i = 1; i <= 9; ++i) {
		if (n>N) break;
		n *= 1LL*d[k];
		dfs(k+1,i+1,counts,n);
	}
	--i;
	for (;i>=1;--i) {
		n /= d[k];
	}
	dfs(k+1,1,counts,n);
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	cin >> N;
	ans = INF, max_counts  = 0;
	d = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	dfs(0,1,1,1);
	cout << ans << endl;
	return 0;
}