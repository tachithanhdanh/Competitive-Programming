#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vector
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD=1e9+7; //998244353
const ll INF = 1e18; //Not too close to LLONG_MAX

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	freopen("art.in","r",stdin);
	freopen("art.out","w",stdout);
	int N; cin >> N;
	vector<vi> grid(N,vi(N)), possible_grid;
	bool used[10]; memset(used,false,sizeof(used));
	int X[2][10],Y[2][10];
	F0R(i,10) X[1][i] = Y[1][i] = 0;
	F0R(i,10) X[0][i] = Y[0][i] = 1000;
	vi colors; used[0] = true;
	F0R(i,N) F0R(j,N) {
		char ch;
		cin >> ch;
		grid[i][j] = int(ch - '0');
		if (used[grid[i][j]]==false){
			used[grid[i][j]] = true;
			colors.pb(grid[i][j]);
		}
		X[0][grid[i][j]] = min(X[0][grid[i][j]],i);
		X[1][grid[i][j]] = max(X[1][grid[i][j]],i);
		Y[0][grid[i][j]] = min(Y[0][grid[i][j]],j);
		Y[1][grid[i][j]] = max(Y[1][grid[i][j]],j);
	}
	memset(used,false,sizeof(used));
	sort(all(colors)); int ans = 0;
	do {
		if (used[colors[0]]) continue;
		possible_grid = grid; each(row,possible_grid) fill(all(row),0);
		each(color,colors) {
			FOR(x,X[0][color],X[1][color]+1) FOR(y,Y[0][color],Y[1][color]+1) possible_grid[x][y] = color;
		}
		if (possible_grid == grid) {
			used[colors[0]] = true; ++ans;
		}
	} while (next_permutation(all(colors)));
	cout << ans << endl;
	return 0;
}
