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
int N, M, dist[MX][MX], xA, yA, xB, yB;
char grid[MX][MX], trace[MX][MX];
vector<char> path;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			if (c == 'A') xA = i, yA = j;
			if (c == 'B') xB = i, yB = j;
			dist[i][j] = MOD;
			if (c == '#') dist[i][j] *= 2;
		}
	}

	// BFS
	queue<pi> q;
	q.push(mp(xA,yA));
	dist[xA][yA] = 0;
	auto isValid = [&](const int& x, const int& y) {
		return x >= 0 && x < N && y >= 0 && y < M && dist[x][y] == MOD;
	};
	while (!q.empty()) {
		pi node = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = node.f+dx[i], y = node.s+dy[i];
			if (isValid(x,y)) {
				dist[x][y] = dist[node.f][node.s]+1;
				trace[x][y] = dc[i];
				q.push(mp(x,y));
			}
		}
	}
	if (dist[xB][yB] == MOD) return cout << no, 0;
	cout << yes << dist[xB][yB] << endl;
	int x = xB, y = yB;
	do {
		path.pb(trace[x][y]);
		for (int i = 0; i < 4; ++i) {
			if (trace[x][y] == d[i]) {
				x -= dx[i], y -= dy[i];
				break;
			}

		}
	} while (!(x == xA && y == yA));
	for (int i = sz(path)-1; i >= 0; --i) cout << path[i];
	return 0;
}
