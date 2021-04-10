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
		freopen((name+".INP").c_str(), "r", stdin); // see /general/io
		freopen((name+".OUT").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, M, ans = 1;
string grid[30];

int main() {
	setIO("CHEEMSMATTRESS");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> grid[i];
	for (int l = 1; l <= N; ++l)
		for (int w = 1; w <= M; ++w)
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (i+l <= N && j+w <= M) {
						bool flag = false;
						for (int k = i; k < i+l; ++k) {
							for (int p = j; p < j+w; ++p) {
								flag |= bool(grid[k][p]-'0');
								if (flag) break;
							}
							if (flag) break;
						}
						if (flag) continue;
						ckmax(ans,(l+w)*2);
					}
	cout << ans;
	return 0;
}
