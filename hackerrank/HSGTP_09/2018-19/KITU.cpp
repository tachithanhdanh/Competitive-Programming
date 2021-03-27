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
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
//variables used for the current problem
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; }
string T, cap, ans;
int maxlen, dp[MX];

void dfs(int K) {
	if (sz(ans) > 26) return;
	for (int i = 1; i < sz(ans); ++i) {
		if (ans[i] <= ans[i-1]) return;
	}
	if (K == sz(cap)) {
		maxlen = max(maxlen, sz(ans)); return;
	}
	ans += cap[K];
	dfs(K+1);
	ans.pop_back();
	dfs(K+1);
}

int main() {
	setIO();	
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	cin >> T;
	for (char& c : T) if (isupper(c)) cap += c;
	if (sz(cap) < 25) dfs(0);
 	else { // LIS O (N ^ 2)]
		fill(all(dp),1); // Initially, all LIS end at position i-th (0 < i < sz(T)) equal to 1.
		for (int i = 0; i < sz(cap); ++i) {
			for (int j = 0; j < i; ++j)
 				if (cap[j] < cap[i]) ckmax(dp[i],dp[j]+1);    
			ckmax(maxlen,dp[i]);
		}
	}
	cout << maxlen;
	return 0;
}
