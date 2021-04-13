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

//variables used for the current problem
int N, M, rooms;
vector<pi> adj[MX][MX];
bool visited[MX][MX], lit[MX][MX];

bool isValid(const int& x, const int& y) {
	return x > 0 && x <= N && y > 0 && y <= N && !visited[x][y];
}

bool isLit(const int& x, const int& y) {
	return lit[x][y];
}

void ff(int& x, int& y) {
	if (!isValid(x,y) || !isLit(x,y)) return;
	visited[x][y] = true;
	for (pi& p : adj[x][y]) {
		int X = p.f, Y = p.s;
		if (!isLit(X,Y)) {
			lit[X][Y] = true;
			++rooms;
			for (int i = 0; i < 4; ++i) {
				int XX = X+dx[i], YY = Y+dy[i];
				if (visited[XX][YY]) ff(X,Y);
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		int X = x+dx[i], Y = y+dy[i];
		ff(X,Y);
	}
	return;
}

int main() {
	setIO("lightson");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		adj[x][y].pb(mp(a,b));
	}
	rooms = 1;
	lit[1][1] = true;
	int x = 1, y = 1;
	ff(x,y);
	cout << rooms;
	return 0;
}
