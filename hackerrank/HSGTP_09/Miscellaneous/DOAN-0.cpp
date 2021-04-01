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
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int maxlen, l, r;

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N;
	cin >> N;
	vector<ll> A(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i]; A[i] += A[i-1];
	}
	map<ll,int> m;
	for (int i = 1; i <= N; ++i) {
		if (m.find(A[i]) == m.end()) m[A[i]] = i;
		else if(ckmax(maxlen,i-m[A[i]])) l = m[A[i]] + 1, r = i;
		if (!A[i]) if(ckmax(maxlen,i)) l = 1, r = i;
		debug(l); debug(r);
		debug(endl);
	}
	cout << l << " " << r;
	return 0;
}
