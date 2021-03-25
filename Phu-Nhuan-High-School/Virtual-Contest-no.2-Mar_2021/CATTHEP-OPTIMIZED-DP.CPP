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
		freopen((name+".INP").c_str(), "r", stdin); // see /general/io
		freopen((name+".OUT").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 3e4+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
ll dp[15][205];

int main() {
	setIO("CATTHEP");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int L;
	cin >> L;
	dp[0][0] = 1; // There is only one way to create sum 0 with 0 numbers.
	for (int K = 1; K <= 12; ++K) for (int N = 1; N < 205; ++N)
		dp[K][N] += (dp[K-1][N-1] + dp[K][N-1]);
	cout << dp[12][L];
	return 0;
}
