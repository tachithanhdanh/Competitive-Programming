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
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
ll N, ans;
vector<bool> check(MX,true);
vi prime;

void sieve() {
	check[0] = check[1] = false;
	for (int i = 2; i < 4; ++i)
		for (int j = i * i; j < MX; j += i)
			check[j] = false;
	for (int i = 5, t = 2; i * i <= MX; i += t, t = 6 - t)
		for (int j = i * i; j < MX; j += i)
			check[j] = false;
	for (int i = 0; i <= N; ++i) if (check[i]) prime.pb(i);
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	sieve();
	ans = 1;
	for (int i = 0; i < sz(prime); ++i) {
		ll p = prime[i], num = 1;
		while (num*p <= N) {
			num *= p;
		}
		ans = (1LL*ans*num)%MOD;
	}
	cout << ans;
	return 0;
}
