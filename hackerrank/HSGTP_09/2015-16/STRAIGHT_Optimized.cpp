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
const int MX = 2e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, X[MX], Y[MX], X1, X2, Y1, Y2, ans;
ll K;

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
	}
	/*
	y = ax + b
	y1 = ax1 + b
	y2 = ax2 + b

	=> a = (y2-y1)/(x2-x1)
	if (x2 == x1) then add INF
	b = y1 - ax1
	if a == k ? then don't add
	*/
	vector<ll> slope(N*(N+1)/2);
	int pos = 0;
	for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
		X1 = X[i], Y1 = Y[i], X2 = X[j], Y2 = Y[j];
		// calculate the slope of the line
		if (X1 == X2) K = INF;
		else K = 1E9 * (Y2 - Y1) / (X2 - X1);
		slope[pos++] = K;
	}
	sort(all(slope));
	ans = 1;
	for (int i = 1; i < sz(slope); ++i) ans += (slope[i] != slope[i-1]);
	cout << ans;
	return 0;
}
