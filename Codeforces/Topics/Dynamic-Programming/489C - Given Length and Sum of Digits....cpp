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
int M, S, pos, sum;
bool dp[105][1000];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	dp[0][0] = true;
	for (int i = 1; i <= 100; ++i) {
		for (int j = 0; j <= 900; ++j) {
			for (int k = 0; k <= 9; ++k) {
				if (j-k >= 0) {
					dp[i][j] |= dp[i-1][j-k];
				}
			}
		}
	}
	cin >> M >> S;
	if (M == 1 && !S) return cout << "0 0", 0;
	if ((M && !S) || dp[M][S] == false) return cout << "-1 -1", 0;

	for (int i = 1; i <= 9; ++i) {
		pos = M-1, sum = S-i;
		if (!dp[pos][sum]) continue;
		cout << i;
		while (pos) {
			for (int i = 0; i <= 9; ++i) {
				if (sum-i >= 0 && dp[pos-1][sum-i]) {
					cout << i;
					--pos;
					sum -= i;
					//flag = true;
					break;
				}
			}
		}
		break;
	}
	cout << ' ';
	pos = M, sum = S;
	while (pos) {
		for (int i = 9; i >= 0; --i) {
			if (sum-i >= 0 && dp[pos-1][sum-i]) {
				cout << i;
				--pos;
				sum -= i;
				break;
			}
		}
	}
	return 0;
}
