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
const int maxn = 4e4+10;

int cntX[maxn], cntY[maxn];
int maxX, minX, maxY, minY;
int mx1, mx2, mn1=maxn, mn2=maxn;
//http://www.usaco.org/index.php?page=viewproblem2&cpid=641
int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	freopen("reduce.in","r",stdin);
	freopen("reduce.out","w",stdout);
	int N;
	cin >> N;
	vector<pi> a(N);
	each(b,a) {
		cin >> b.f >> b.s; ++cntX[b.f]; ++cntY[b.s];
		mn1=min(mn1,b.f);
		mn2=min(mn2,b.s);
		mx1=max(mx1,b.f);
		mx2=max(mx2,b.s);
	}
	int ans = 2*MOD;
	each(b,a) {
		--cntX[b.f]; --cntY[b.s];
		FOR(i,mn1,mx1+1) if (cntX[i]) {
			minX = i; break;
		}
		FOR(i,mn2,mx2+1) if (cntY[i]) {
			minY = i; break;
		}
		ROF(i,mn1,mx1+1) if (cntX[i]) {
			maxX = i; break;
		}
		ROF(i,mn2,mx2+1) if (cntY[i]) {
			maxY = i; break;
		}
		ans = min(ans,(maxX-minX)*(maxY-minY));
		++cntX[b.f]; ++cntY[b.s];
	}
	cout << ans << endl;
	return 0;
}