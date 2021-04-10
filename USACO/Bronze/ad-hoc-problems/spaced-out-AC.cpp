#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

using ll = long long;

//vectors
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
const string yes="Yes",no="No";
const int MOD=1e9+7; //998244353
const int maxn=1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int grid[1001][1001], N;
int sum[2], horizontalAnswer, verticalAnswer;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	cin >> N;
	F0R(y,N) F0R(x,N) cin >> grid[y][x];
	F0R(y,N) {
		sum[0] = sum[1] = 0;
		F0R(x,N) {
			//Calculate for the rows alternating case.
			sum[x&1] += grid[y][x];
		}
		horizontalAnswer += max(sum[0], sum[1]);
	}
	F0R(x,N) {
		sum[0] = sum[1] = 0;
		F0R(y,N) {
			//Calculate for the columns alternating case.
			sum[y&1] += grid[y][x];
		}
		verticalAnswer += max(sum[0], sum[1]);
	}
	cout << max(horizontalAnswer, verticalAnswer);
	return 0;
}
/*
Problem statement: http://www.usaco.org/index.php?page=viewproblem2&cpid=1088
Official analysis: http://www.usaco.org/current/data/sol_prob3_silver_jan21.html
In this problem, there are 2 cases to consider:
	Case #1: Rows alternating (horizontally alternating)
	Something like this : (0 means no cows, 1 means a cow)
	0 1 0 1 0 1 0
	0 1 0 1 0 1 0
	1 0 1 0 1 0 1
	0 1 0 1 0 1 0
	1 0 1 0 1 0 1
	1 0 1 0 1 0 1
	0 1 0 1 0 1 0
	Case #2: Columns alternating (vertically alternating)
	Something like this : (0 means no cows, 1 means a cow)
	1 0 0 0 1 0 1
	0 1 1 1 0 1 0
	1 0 0 0 1 0 1
	0 1 1 1 0 1 0
	1 0 0 0 1 0 1
	0 1 1 1 0 1 0
	1 0 0 0 1 0 1
	Our task is to calculate the maximum value for all positions that cows appear in
*/
