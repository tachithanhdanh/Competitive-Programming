#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
typedef long long ll;

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
int N, H[2][MX];
ll dp[2][2][MX], ans;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < N; ++j)
			cin >> H[i][j];
	dp[1][0][1] = H[0][0];
	dp[1][1][1] = H[1][0];
	ckmax(ans,ll(max(H[0][0],H[1][0])));
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < 2; ++j) {
			ll temp1 = max(dp[1][j][i-1],dp[1][1-j][i-1]);
			ll temp2 = max(dp[0][j][i-1],dp[0][1-j][i-1]);
			ll temp3 = max(dp[1][1-j][i-1],dp[1][j][i-2]);
			ckmax(dp[0][j][i],max(temp1,temp2));
			ckmax(dp[1][j][i],max(temp2,temp3)+H[j][i-1]);
			ckmax(ans,max(dp[0][j][i],dp[1][j][i]));
		}
	}
	cout << ans;
	return 0;
}
