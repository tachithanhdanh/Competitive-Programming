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
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

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
int N, cost[MX];
ll dp[2][MX];
string S[2][MX];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < 2; ++i) fill(dp[i],dp[i]+N+5,INF);
	for (int i = 0; i < N; ++i) cin >> cost[i];
	for (int i = 0; i < N; ++i) {
		cin >> S[0][i];
		S[1][i] = S[0][i];
		reverse(all(S[1][i]));
	}
	dp[0][0] = 0;
	dp[1][0] = cost[0];
	for (int i = 1; i < N; ++i) {
		if (S[0][i] >= S[0][i-1]) ckmin(dp[0][i],dp[0][i-1]);
		if (S[1][i] >= S[0][i-1]) ckmin(dp[1][i],dp[0][i-1]+cost[i]);
		if (S[0][i] >= S[1][i-1]) ckmin(dp[0][i],dp[1][i-1]);
		if (S[1][i] >= S[1][i-1]) ckmin(dp[1][i],dp[1][i-1]+cost[i]);
		db(dp[0][i]);
		db(dp[1][i]);
	}
	if (dp[0][N-1] == dp[1][N-1] && dp[0][N-1] == INF) cout << -1;
	else cout << min(dp[0][N-1],dp[1][N-1]);
	return 0;
}
