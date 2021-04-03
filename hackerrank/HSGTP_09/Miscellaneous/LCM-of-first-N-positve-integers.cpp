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
int N, factors[MX], ans;
vector<bool> check(MX,true);
vi prime;

int fastpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y&1) res = (1LL*res*x)%MOD;
		y >>= 1;
		x = (1LL*x*x)%MOD;
	}
	return res;
}

void sieve() {
	check[0] = check[1] = false;
	for (int i = 2; i < 4; ++i)
		for (int j = i * i; j < MX; j += i)
			check[j] = false;
	for (int i = 5, t = 2; i * i <= MX; i += t, t = 6 - t)
		for (int j = i * i; j < MX; j += i)
			check[j] = false;
	for (int i = 0; i < MX; ++i) if (check[i]) prime.pb(i);
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	sieve();
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		vector<pi> fact;
		int num = i;
		for (int j = 0; j < sz(prime) && num != 1; ++j) {
			if (num % prime[j] == 0) {
				int cnt = 0;
				while (num % prime[j] == 0) {
					num /= prime[j];
					++cnt;
				}
				fact.pb(mp(prime[j],cnt));
			}
			if (check[num]) {
				fact.pb(mp(num,1));
				break;
			}
		}
		for (pi& p : fact) ckmax(factors[p.f],p.s);
	}

	ans = 1;
	for (int i = 0; i < MX; ++i)
		if (factors[i]) ans = (1LL*ans*fastpow(i,factors[i]))%MOD;
	cout << ans;
	return 0;
}

/*
Problems statement: https://drive.google.com/file/d/14ZLnZU3DCteyojubZLcO5XCTrIdcQA2m/view
Solutions: https://drive.google.com/file/d/1Cy0NLEVbaW0HZmKAjzYFqlAdGpHDgoiB/view
Documentation: https://drive.google.com/file/d/1CfPWLhmysDDJX4JV9s9pL9VsoZ8Otp5j/view
*/