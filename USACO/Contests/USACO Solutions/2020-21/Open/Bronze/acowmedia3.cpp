#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
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
const string yes="YES\n",no="NO\n";
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

int N, M, cow, cows[1050][1050], ans;
char grid[1050][1050];
set<pi> used;
vpi pos;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'C') cows[i][j] = ++cow;
			if (grid[i][j] == 'G') pos.pb(mp(i,j));
		}
	}
	auto update = [](int& x, int& y) {
		vi index;
		for (int i = 1; i <= 3; i += 2) if(grid[x][y+dy[i]] == 'C') index.pb(cows[x][y+dy[i]]);
		for (int i = 0; i <= 2; i += 2) if(grid[x+dx[i]][y] == 'C') index.pb(cows[x+dx[i]][y]);
		if (sz(index) < 2) return 0;
		if (sz(index) > 2) return 1;
		if (index.front() > index.back()) swap(index.front(),index.back());
		used.insert(mp(index.front(),index.back()));
		return 0;
	};
	for (pi& p : pos) ans += update(p.f,p.s);
	cout << ans+sz(used);
 	return 0;
}
