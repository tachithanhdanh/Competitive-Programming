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
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
ll dp[2][MX][MX];
//https://usaco.guide/problems/usaco-cow-checklist/solution
int main() {
	setIO("checklist");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int H, G;
	cin >> H >> G;
	vector<pi> h(H), g(G);

	for (pi& p : h) cin >> p.f >> p.s;
	for (pi& p : g) cin >> p.f >> p.s;

	//calculating distance function
	auto sqr = [&](const int& a) -> ll { return 1LL * a * a; };
	auto D = [&](const pi& a, const pi& b) -> ll { return 1LL * sqr(a.f-b.f) + sqr(a.s-b.s); };

	//dp[0][i][j] is min cost to visit i holsteins and j guernseys ending with holstein
	//dp[1][i][j] is min cost to visit i holsteins and j guernseys ending with guernsey
	for (int i = 0; i < MX; ++i)
		for (int j = 0; j < MX; ++j)
			for (int k = 0; k < 2; ++k)
				dp[k][i][j] = INF;

	//farmer john must start with the first holstein, so the cost is 0
	dp[0][1][0] = 0;

	for (int i = 0; i <= H; ++i) {
		for (int j = 0; j <= G; ++j) {
			if (i && j)
			{
				//go from gcows[j - 1] to hcows[i - 1]
				ckmin(dp[0][i][j],dp[1][i-1][j]+D(g[j-1],h[i-1]));

				//go from hcows[i - 1] to gcows[j - 1]
				ckmin(dp[1][i][j],dp[0][i][j-1]+D(h[i-1],g[j-1]));
			}
			if (i > 1)
			{
				//go from hcows[i - 2] to hcows[i - 1]
				ckmin(dp[0][i][j],dp[0][i-1][j]+D(h[i-2],h[i-1]));
			}
			if (j > 1)
			{
				//go from gcows[j - 2] to gcows[j - 1]
				ckmin(dp[1][i][j],dp[1][i][j-1]+D(g[j-2],g[j-1]));
			}
		}
	}

	cout << dp[0][H][G];
	return 0;
}
