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
int a[3];
int min_ans, max_ans, max_gap;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	each(b,a) cin >> b;
	sort(all(a));
	if (a[2]-a[0] == 2) {
		cout << min_ans << endl << max_ans << endl; return 0;
	}
	if (a[2]-a[1] == 2 || a[1]-a[0] == 2) min_ans = 1;
	else min_ans = 2;
	max_gap = max(a[2]-a[1],a[1]-a[0]);
	max_ans = max_gap - 1;
	cout << min_ans << endl << max_ans << endl;
	return 0;
}
