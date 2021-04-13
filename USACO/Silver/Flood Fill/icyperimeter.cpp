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
#define debug(x) cerr << (#x) << " is " << (x) << endl
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
int N, p, area;
string grid[MX];
vector<pi> ans;
bool visited[MX][MX];

bool isvalid(const int& x, const int& y) {
	return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '#' && !visited[x][y];
}

bool isEmpty(const int& x, const int& y) {
	if (x < 0 || y < 0 || x >= N || y >= N) return true;
	if (grid[x][y] == '.') return true;
	return false;
}

void ff(int& x, int&
		 y) {
	visited[x][y] = true;
	++area;
	for (int i = 0; i < 4; ++i) {
		int X = x+dx[i], Y = y+dy[i];
		if (isvalid(X,Y))
			ff(X,Y);
		if(isEmpty(X,Y))
			++p;
	}
}

int main() {
	setIO("perimeter");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> grid[i];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && grid[i][j] == '#') {
				p = area = 0;
				ff(i,j);
				ans.pb(mp(area,p));
			}
		}
	}
	sort(all(ans),[](const pi& a, const pi& b) {
		if (a.f == b.f) return a.s < b.s;
		return a.f > b.f;
	});
	cout << ans[0].f << " " << ans[0].s;
	return 0;
}
