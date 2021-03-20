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
int dp[MX], End[MX];
//https://vietcodes.github.io/code/93/index.html
int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int N;
	cin >> N;
	vector<pi> req(N);
	for (pi& task : req) cin >> task.f >> task.s;
	sort(all(req),[](const pi& t1, const pi& t2) {
		if (t1.s == t2.s) return t1.f < t2.f;
		return t1.s < t2.s;
	});
	for (int i = 0; i < N; ++i) End[i] = req[i].s;
	for (int i = 1; i <= N; ++i)
		dp[i] = max(dp[i-1], req[i-1].s - req[i-1].f + dp[upper_bound(End,End + N,req[i-1].f) - End]);
	cout << dp[N];
	return 0;
}
