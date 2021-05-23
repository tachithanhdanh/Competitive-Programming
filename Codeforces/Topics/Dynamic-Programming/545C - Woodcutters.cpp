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
int N, maxX[2][MX];
ll dp[2][MX];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	vector<pi> v(N);
	for (pi& p : v) cin >> p.f >> p.s;
	sort(all(v));
	v.pb(mp(2*MOD,2*MOD));
	dp[1][1] = 1;
	maxX[1][1] = maxX[0][1] = maxX[0][0] = maxX[1][0] = v[0].f;
	for (int i = 2; i <= N; ++i) {
		pi p = v[i-1];
		ckmax(dp[0][i],max(dp[0][i-1],dp[1][i-1]));
		maxX[1][i] = maxX[0][i] = p.f;
		for (int j = 0; j < 2; ++j)
			if (p.f-p.s > maxX[j][i-1])
				if(ckmax(dp[1][i],dp[j][i-1]+1))
					maxX[1][i] = p.f;
		if (p.f+p.s < v[i].f)
			if(ckmax(dp[1][i],max(dp[0][i-1],dp[1][i-1])+1))
				maxX[1][i] = p.f+p.s;
	}
	cout << dp[1][N];
	return 0;
}
