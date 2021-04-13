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
const char dc[4] = {'D', 'R', 'U', 'L'};

//variables used for the current problem
int N, M, d[MX][MX], dist[MX][MX];
char grid[MX][MX];
vector<pi> ESC, Mon;
vector<char> path;
vi D;
pi A;

bool isValid(const int& x, const int& y) {
	return x >= 0 && x < N && y >= 0 && y < M && dist[x][y] == MOD;
}

void BFS(pi Start = mp(-1,-1)) {
	queue<pi> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (grid[i][j] != '#') dist[i][j] = MOD;
			if (grid[i][j] == 'M' && Start == mp(-1,-1)) { // used when BFS for monsters
				dist[i][j] = 0;
				q.push(mp(i,j));
			}
		}
	}
	if (Start != mp(-1,-1)) { // BFS for A
		dist[Start.f][Start.s] = 0;
		q.push(Start);
	}

	while (!q.empty()) {
		pi node = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = node.f+dx[i], y = node.s+dy[i];
			if (isValid(x,y)) {
				dist[x][y] = dist[node.f][node.s] + 1;
				q.push(mp(x,y));
				if (Start != mp(-1,-1)) {
					d[x][y] = i;
				}
			}
		}
	}
	return;
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') A = mp(i,j);
			if (grid[i][j] == 'M') Mon.pb(mp(i,j));
			if (grid[i][j] == '.' && (i == 0 || i == N-1 || j == 0 || j == M-1)) ESC.pb(mp(i,j));
			if (grid[i][j] == '#') dist[i][j] = 2*MOD;
		}
	}

	if (A.f == 0 || A.f == N-1 || A.s == 0 || A.s == M-1) return cout << yes << 0, 0; // No boundary squares

	// BFS to find shortest path from the monsters to the boundary squares.
	BFS();
	D.resize(sz(ESC),2*MOD);
	for (int i = 0; i < sz(ESC); ++i) {
		ckmin(D[i],dist[ESC[i].f][ESC[i].s]);
	}
	BFS(A);
	for (int i = 0; i < sz(ESC); ++i) {
		int x = ESC[i].f, y = ESC[i].s;
		if (dist[x][y] < D[i]) {
			cout << yes << dist[x][y] << endl;
			do {
				int dir = d[x][y];
				path.pb(dc[dir]);
				x -= dx[dir], y -= dy[dir];
			} while (x != A.f || y != A.s);
			for (int i = sz(path)-1; i >= 0; --i) cout << path[i];
			return 0;
		}
	}
	cout << no;
	return 0;
}
