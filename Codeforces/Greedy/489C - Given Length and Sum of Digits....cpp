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
int M, S;
string maxans, minans;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> M >> S;
	if (M == 1 && S == 0) return cout << "0 0", 0;
	if (M*9 < S || S == 0) return cout << "-1 -1", 0;
	for (int i = 0; i < M; ++i) {
		int x = min(9,S);
		S -= x;
		maxans += char(x+'0');
	}
	minans = maxans;
	reverse(all(minans));
	if (minans[0] == '0') {
		for (int i = 1; i < sz(minans); ++i) {
			if (minans[i] != '0') {
				++minans[0];
				--minans[i];
				break;
			}
		}
	}
	cout << minans+" "+maxans;
	return 0;
}
// https://codeforces.com/contest/489/submission/8719555