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
int dp[3][21][MX], state[MX], N, K, ans;

int main() {
	setIO("hps");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		char gesture;
		cin >> gesture;
		if (gesture == 'P') state[i] = 1;
		else if (gesture == 'S') state[i] = 2;
	}
	for (int n = 1; n <= N; ++n) for (int k = 0; k <= K; ++k)  for (int s = 0; s < 3; ++s) {
		if (k) dp[s][k][n] = max(dp[s][k][n-1],max(dp[(s+1)%3][k-1][n-1],dp[(s+2)%3][k-1][n-1])) + (s == state[n-1]);
		else dp[s][k][n] = dp[s][k][n-1] + (s == state[n-1]);
	}
	cout << max(dp[0][K][N],max(dp[1][K][N],dp[2][K][N]));
	return 0;
}
