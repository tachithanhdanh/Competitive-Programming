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
const char dc[4] = {'r', 'u', 'l', 'd'};

//variables used for the current problem
int A, B;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> A >> B;
	auto isPrime = [](int n) {
		if (n < 2) return false;
		if (n == 2 || n == 3 || n == 5 || n == 7) return true;
		if (!(n&1) || !(n%3) || !(n%5) || !(n%7)) return false;
		for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
			if (!(n%i))
				return false;
		return true;
	};
	for (int i = A; i <= B; ++i)
		if (isPrime(i))
			cout << i << endl;
	return 0;
}
