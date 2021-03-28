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
int dp[MX][MX], grid[MX][MX], maxSum = -MOD; 
//Note #1: You have to set the value of maxSum to -INF because there are negative numbers on the grid

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) cin >> grid[i][j];
	//Note #2: You also have to set all value of the DP array to -INF since the maximum sum of the grid path may be a negative number.
	for (int i = 0; i < MX; ++i) fill(all(dp[i]),-MOD);
	//for (int i = 0; i < M; ++i) for (int j = 0; j < N; ++j) cout << dp[i][j] << " \n"[j==N-1];
	for (int i = 0; i < M; ++i) dp[i][0] = grid[i][0];
	for (int j = 1; j < N; ++j) for (int i = 0; i < M; ++i) {
		if (i) ckmax(dp[i][j],dp[i-1][j-1]);
		ckmax(dp[i][j],max(dp[i][j-1],dp[i+1][j-1]));
		dp[i][j] += grid[i][j];
	}
	for (int i = 0; i < M; ++i) ckmax(maxSum,dp[i][N-1]);
	cout << maxSum;
	return 0;
}
