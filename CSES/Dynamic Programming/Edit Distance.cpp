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
const int MX = 5e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
//variables used for the current problem
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
string N, M;
int n, m;
//Editorial : https://codeforces.com/blog/entry/70018
int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	n = sz(N), m = sz(M);
	vector<vi> dp(n+1,vi(m+1,MOD));
	dp[0][0] = 0;
	for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) {
		if (i) ckmin(dp[i][j],dp[i-1][j]+1); // Operation 1
		if (j) ckmin(dp[i][j],dp[i][j-1]+1); // Operation 2
		if (i && j) ckmin(dp[i][j],dp[i-1][j-1] + (N[i-1] != M[j-1])); //Operation 3
	}
	cout << dp[n][m];
	return 0;
}