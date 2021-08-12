#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
using str = string;

//vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//constant initialization
const str yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

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


int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int T;
	cin >> T;
	while (T--) {
		ll num[2], bin[2][65];
		cin >> num[0] >> num[1];
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 64; ++j) {
				bin[i][j] = bool(num[i] & (1LL << j));
			}
		}
		//if (T == 0) cout << bool(num[0] & (1LL << 4));
		ll ans = 0, f[65];
		bool isValid = true;
		for (int i = 0; i < 64; ++i) {
			if (bin[0][i] == bin[1][i]) f[i] = 0;
			else if (bin[0][i] == 1 && bin[1][i] == 0) f[i] = 1;
			else isValid = false;
			ans += (f[i] << i);

		}
		//cout << ans << endl;
		if (!isValid) cout << -1 << endl;
		else cout << ans << endl;
	}
 	return 0;
}
