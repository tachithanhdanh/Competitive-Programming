#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

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
#define trav(a,x) for (auto& a : x)

//variables used for the current problem
int n,ans; vi a;

//https://www.hackerrank.com/contests/ctin-1922-level-0/challenges/nhung-chu-bo-choi-bong-chay-cow-baseball/
//http://www.usaco.org/index.php?page=viewproblem2&cpid=359
//http://www.usaco.org/current/data/sol_baseball.html

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("baseball.in","r",stdin);
	freopen("baseball.out","w",stdout);
	cin >> n;
	a.rsz(n);
	trav(b,a) cin >> b;
	sort(all(a));
	F0R(i,n) FOR(j,i+1,n) FOR(k,j+1,n) if (a[k]-a[j]<=2*(a[j]-a[i]) && a[k]-a[j]>=a[j]-a[i]) ++ans;
	cout << ans << endl;
	return 0;
}
