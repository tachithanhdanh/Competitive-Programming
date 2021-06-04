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
const int MX = 2e4+10;
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

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int A, B;
	cin >> A >> B;
	int ans = 0;
	auto GCD = [](int a, int b) -> int {
		// GCD(a,b) = GCD(a,a%b) if (b != 0)
		// else GCD(a,b) = a (because b == 0)
		while (b) {
			swap(a,b);
			b %= a;
		}
		return a;
	};
	auto friendly = [&](int i) -> bool {
		int N = i, M = 0;
		while (i) {
			M *= 10;
			M += i % 10;
			i /= 10;
		}
		//cout << N << " " << M << endl;
		return GCD(N,M) == 1;
	};
	for (int i = A; i <= B; ++i) {
		ans += friendly(i);
	}
	cout << ans;
 	return 0;
}
