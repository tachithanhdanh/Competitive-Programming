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
const int MX = 2e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

//variables used for the current problem
int inp[405][405], pref[810][810], N, K, ans;

int main() {
	setIO("lazy");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> K;
	for (int i = 1; i <= N ; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> inp[i][j];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			pref[i+j-1][N-i+j] = inp[i][j];
	for (int i = 1; i <= N*2-1; ++i)
		for (int j = 1; j <= N*2-1; ++j)
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + pref[i][j];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			// pref[i+j-1][N-i+j] = inp[i][j];
			int centerI = i+j-1, centerJ = N-i+j;
			int bottomI = min(N*2-1,centerI+K), rightJ = min(N*2-1,centerJ+K);
			int topI = max(1,centerI-K), leftJ = max(1,centerJ-K);
			int TotalUnitsOfGrass = pref[bottomI][rightJ] - pref[bottomI][leftJ-1] - pref[topI-1][rightJ] + pref[topI-1][leftJ-1];
			ckmax(ans,TotalUnitsOfGrass);
		}
	}
	//cout << pref[7][7] - pref[7][2] - pref[2][7] + pref[2][2] << endl;
	cout << ans;
 	return 0;
}
