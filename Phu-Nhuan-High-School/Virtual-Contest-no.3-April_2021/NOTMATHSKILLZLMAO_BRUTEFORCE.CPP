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
const int MX = 2e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, K;
ll A[MX], ans, S;

ll GCD(ll a, ll b) {
	while (b) {
		swap(a,b);
		b=b%a;
	}
	return a;
}

int main() {
	setIO("NOTMATHSKILLZLMAO");
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		//A[i] = i*1e18+1e6;
	}
	for (int i = 0; i < N-K+1; ++i) {
		//cout << A[i] << " " << A[i+1];
		S = GCD(A[i],A[i+1]);
		for (int j = i+2; j < i+K; ++j) {
			S = GCD(S,A[j]);
			//cout << " " << A[j];
		}
		//cout << endl << S << endl;
		ckmax(ans,S);
	}
	cout << ans;
	return 0;
}
