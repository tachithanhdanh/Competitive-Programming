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
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

//variables used for the current problem
int R, C, dist[MX][MX], xB, xC, yB, yC;
char grid[MX][MX];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> grid[i][j];
			dist[i][j] = MOD;
			if (grid[i][j] == 'B') xB = i, yB = j, dist[xB][yB] = 0;
			if (grid[i][j] == 'C') xC = i, yC = j;
			if (grid[i][j] == '*') dist[i][j] *= 2;
		}
	}
	// BFS
	queue<pi> q;
	q.push(mp(xB,yB));
	auto isValid = [&](const int& X, const int& Y) {
		return X >= 0 && X < R && Y >= 0 && Y < C && dist[X][Y] == MOD;
	};
	while (!q.empty()) {
		int x = q.front().f, y = q.front().s;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int X = x+dx[i], Y = y+dy[i];
			if (isValid(X,Y)) {
				dist[X][Y] = dist[x][y] + 1;
				q.push(mp(X,Y));
			}
		}
	}
	cout << dist[xC][yC];
	return 0;
}
