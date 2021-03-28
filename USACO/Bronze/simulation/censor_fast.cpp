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
string S, T, R;
//Time complexity: O(TS), which is fast enough
int main() {
	setIO("censor");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> S >> T;
	for (int i = 0; i < sz(S); ++i) {
		R += S[i];
		if (sz(R) >= sz(T) && R.substr(sz(R) - sz(T)) == T)
			R.erase(sz(R) - sz(T));
	}
	cout << R;
	return 0;
}
