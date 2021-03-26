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
const int MX = 2e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int n,grid[MX][MX],x,y,z,t,ans;

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z >> t;
		x+=103; y+=103; z+=103; t+=103;
		++grid[x][t]; ++grid[z][y]; --grid[x][y]; --grid[z][t];
	}
	for (int i = 1; i < MX; ++i) for (int j = 1; j < MX; ++j) {
		grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
		ans += grid[i][j] > 0;
	}
	cout << ans;
	return 0;
}
