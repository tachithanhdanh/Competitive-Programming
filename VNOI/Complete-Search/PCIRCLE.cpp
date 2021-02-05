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

int N; ll pos; vector<vi> ans; vi a,num; bool used[21];
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

void dfs(int k) {
	if (k>1 && binary_search(all(prime), a[k-1] + a[k-2]) == false) return;
	if (k == 2*N) {
		if (binary_search(all(prime),a.front()+a.back())) {
			if (pos < 10000) ans[pos] = a;
			++pos;
		}
		return;
	}
	each(n,num) {
		if (!used[n]) {
			a[k] = n; used[n] = true;
			dfs(k+1); used[n] = false;
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif // LOCAL
	cin >> N;
	a.rsz(2*N); a[0] = 1;
	num.rsz(2*N-1); iota(all(num),2);
	ans.rsz(10000);
	dfs(1);
	cout << pos << endl;
	F0R(i,min(10000,int(pos))) {
		each(res,ans[i]) cout << res << " ";
		cout << endl;
	}
	return 0;
}
