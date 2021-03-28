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

int dp[2][60001];

https://vnoi.info/problems/NKTICK/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int N; cin >> N;
	vi t(N), r(N);
	each(a,t) cin >> a;
	each(a,r) cin >> a;
	FOR(i,1,N+1) {
		dp[0][i] = dp[0][i-1] + t[i-1];
	}
	dp[1][1] = r[0];
	FOR(i,2,N+1) {
		dp[1][i] = min(dp[0][i-2],dp[1][i-2]) + r[i-2];
		dp[0][i] = min(dp[0][i-1],dp[1][i-1]) + t[i-1];
	}
	cout << min(dp[0][N],dp[1][N]);
	return 0;
}