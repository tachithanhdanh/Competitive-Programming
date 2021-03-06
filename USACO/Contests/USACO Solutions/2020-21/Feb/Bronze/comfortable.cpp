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
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

//variables used for the current problem
int N, grid[MX][MX], cnt;
bool check[MX][MX];

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		++x; ++y;
		check[x][y] = true;
		for (int j = 0; j < 4; ++j) {
			++grid[x+dx[j]][y+dy[j]];
			if (check[x+dx[j]][y+dy[j]]) {
				if (grid[x+dx[j]][y+dy[j]] == 3) ++cnt;
				if (grid[x+dx[j]][y+dy[j]] == 4) --cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
