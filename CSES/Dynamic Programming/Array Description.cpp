#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(x)
#endif // LOCAL


void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int dp[MX][110], ans;
// Editorial: https://usaco.guide/solutions/cses-1746?lang=cpp
int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N, M;
	cin >> N >> M;
	int x0;
	cin >> x0;
	if (x0) dp[0][x0] = 1;
	else for (int i = 1; i <= M; ++i) dp[0][i] = 1;
	for (int i = 1; i < N; ++i) {
		int x;
		cin >> x;
		if (x) for (int k = 0; k < 3; ++k) (dp[i][x] += dp[i-1][x+dx[k]]) %= MOD;
		else for (int j = 1; j <= M; ++j)
			for (int k = 0; k < 3; ++k) (dp[i][j] += dp[i-1][j+dx[k]]) %= MOD;

	}
	for (int i = 1; i <= M; ++i) (ans += dp[N-1][i]) %= MOD;
	cout << ans;
	return 0;
}
