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
#define db(x) 42
#endif // LOCAL

//constant initialization
const str yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 2e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

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

void solve() {
	int n, k, a[MX]{}, cnt[32]{};
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 31; ++j) {
			cnt[j] += ((a[i] & (1 << j)) != 0);
		}
	}
	// for (int i = 30; i >= 0; --i) cout << cnt[i] << " ";
	// cout << endl;
	for (int i = 30; i >= 0; --i) {
		// cout << "cnt [" << i << "] " << cnt[i] << endl; 
		if (k >= (n-cnt[i])) {
			k -= (n-cnt[i]);
			cnt[i] = n;
			// cout << "cnt " << i << endl;
		}
	}
	vpi v;
	for (int i = 0; i < 31; ++i) v.pb(mp(cnt[i],i));
	sort(rbegin(v),rend(v));
	for (int i = 0; i < 31; ++i) {
		if (v[i].f == n) continue;
		else {
			if (k >= (n-v[i].f)) {
				k -= (n-v[i].f);
				v[i].f = n;
			}
		}
	}
	int ans{};
	for (int i = 0; i < 31; ++i) {
		// cout << "bit: " << v[i].s << " " << v[i].f << endl;
		if (v[i].f == n) ans += (1 << v[i].s);
	}
	cout << ans << endl;
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}