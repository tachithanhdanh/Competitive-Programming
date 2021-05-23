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
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, A[MX], dp[4][MX], ans = MOD;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < 4; ++i) fill(1+all(dp[i]),MOD);
	for (int i = 1; i <= N; ++i) {
		bool contest = A[i-1]&1; // 1 3
		bool gym = A[i-1] >= 2; // 2 3
		if (contest) {
			ckmin(dp[1][i],min(dp[2][i-1],dp[0][i-1]));
		}
		if (gym) {
			ckmin(dp[2][i],min(dp[1][i-1],dp[0][i-1]));
		}
		if (gym && contest) {
			dp[3][i] = dp[0][i-1];
		}
		for (int j = 0; j < 4; ++j) ckmin(dp[0][i],1+dp[j][i-1]);
	}
	for (int i = 0; i < 4; ++i) ckmin(ans,dp[i][N]);
	cout << ans;
	return 0;
}
