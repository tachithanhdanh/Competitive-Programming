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
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[8] = {1,0,-1,0,1,1,-1,-1}, dy[8] = {0,1,0,-1,1,-1,1,-1}; // for every grid problem!!

//variables used for the current problem
int grid[MX][MX], N, M, peak;
bool visited[MX][MX], ispeak;

bool isvalid(const int& X, const int& Y) {
	return X >= 0 && X < N  && Y >= 0 && Y < M;
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 8; ++i) {
		int X = x + dx[i], Y = y + dy[i];
		if (visited[X][Y] && grid[x][y] < grid[X][Y]) { ispeak = false; return; }
		if (isvalid(X,Y) && !visited[X][Y]) {
			if (grid[x][y] == grid[X][Y]) dfs(X,Y);
			else if (grid[x][y] < grid[X][Y]) { ispeak = false; return; }
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
	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> grid[i][j];
	//for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) visited[i][j] = !grid[i][j];
	for (int x = 0; x < N; ++x) for (int y = 0; y < M; ++y) if (!visited[x][y] && isvalid(x,y)) {
		ispeak = true;
		for (int i = 0; i < 8; ++i) if (isvalid(x+dx[i],y+dy[i])) ispeak &= grid[x][y] >= grid[x+dx[i]][y+dy[i]];
		if (ispeak) {
			//cout << x << " " << y << endl;
			dfs(x,y); peak += ispeak;
		}
	}
	cout << peak;
	return 0;
}
