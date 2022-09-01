#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
using str = string;

// vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back

// pairs
using pi = pair<int, int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

// set min-max value.
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

// constant initialization
const str yes="YES\n", no="NO\n";
const int MOD = 1e9 + 7; // 998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

bool ok(const int& i, const int& j, const int& n, const int& m, const vector<vb>& vis, const vector<vector<char>>& g) {
	return (i >= 0 && j >= 0 && i < n && j < m && g[i][j] == '*' && !vis[i][j]);
}

void dfs(const int& x, const int& y, const int& n, const int& m, vector<vb>& vis, vpi& nodes, const vector<vector<char>>& g) {
	vis[x][y] = true;
	nodes.pb(mp(x,y));
	for (int k = 0; k < 4; ++k) {
		int xx = x+dx[k], yy = y+dy[k];
		if (ok(xx,yy,n,m,vis,g)) {
			dfs(xx,yy,n,m,vis,nodes,g);
		}
	}
}

bool checkL(const vpi& a) {
	int x[3], y[3];
	for (int i = 0; i < 3; ++i) x[i] = a[i].f, y[i] = a[i].s;
	if (x[0] == x[1]-1 && x[1] == x[2] && y[0] == y[1] && y[1] == y[2]+1) return true;
	if (x[0] == x[1]-1 && x[1] == x[2] && y[0] == y[1] && y[2] == y[1]+1) return true;
	if (y[0] == y[1]-1 && y[1] == y[2] && x[0] == x[1] && x[2] == x[1]+1) return true;
	if (x[0] == x[1]-1 && x[0] == x[2] && y[0] == y[1] && y[2] == y[1]+1) return true;
	return false;
}

#define rip return void(cout << no);

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n,vector<char>(m));
	vector<vb> vis(n,vb(m));
	vector<vpi> connected_components;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ok(i,j,n,m,vis,g)) {
				vpi nodes;
				dfs(i,j,n,m,vis,nodes,g);
				if (sz(nodes) != 3) return void(cout << no);
				connected_components.pb(nodes);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			vis[i][j] = false;
		}
	}
	for (vpi& nodes: connected_components) {
		if (checkL(nodes)) {
			for (pi& p: nodes) {
				for (int i = -1; i <= 1; i += 2) {
					for (int j = -1; j <= 1; j += 2) {
						int x = p.f+i, y = p.s+j;
						if (ok(x,y,n,m,vis,g) && find(all(nodes),mp(x,y)) == end(nodes)) 
							rip;
					}
				}
			}
		}
		else rip;
	}
	cout << yes;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	return 0;
}