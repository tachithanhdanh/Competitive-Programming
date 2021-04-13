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
#define debug(x) cerr << (#x) << " is " << (x) << endl
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
const int MX = 2e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

//variables used for the current problem
string S;
int K, A, B;
bool dp[MX][MX];
vi ans;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> K >> A >> B >> S;
	dp[0][0] = true;
	for (int i = 1; i <= K; ++i)
		for (int k = 1; k < MX; ++k)
			for (int j = A; j <= B; ++j)
				if (k-j >= 0)
					dp[i][k] |= dp[i-1][k-j];
	if (dp[K][sz(S)] == false) return cout << "No solution", 0;
	int num = K, sub = sz(S);
	ans.pb(sub);
	// Traceback dp
	while (num && sub) {
		for (int i = A; i <= B; ++i) {
			if (sub-i >= 0 && dp[num-1][sub-i]) {
				--num;
				ans.pb(sub-i);
				sub -= i;
				//cout << sub-1 << endl;
				break;
			}
		}
	}
	reverse(all(ans));
	//for (int i : ans) cout << i << endl;
	//cout << ans.back();
	for (int i = 0; i < sz(ans)-1; ++i) {
		for (int j = ans[i]; j < ans[i+1]; ++j) {
			cout << S[j];
		}
		cout << endl;
	}
	return 0;
}
