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
const string yes="yes\n",no="no\n";
const int MOD=1e9+7; //998244353
const int maxn=1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N, K;
vi adj[100];
vector<vector<string>> sub_populations;
vector<string> all_characteristics;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#endif
	freopen("evolution.in", "r", stdin);
	freopen("evolution.out", "w", stdout);
	cin >> N;
	sub_populations.rsz(N);
	each(characteristics,sub_populations) {
		cin >> K;
		characteristics.rsz(K);
		each(characteristic,characteristics) {
			cin >> characteristic;
			bool found = false;
			each(sub_characteristic,all_characteristics)
				found |= characteristic == sub_characteristic;
			if (found == false) all_characteristics.pb(characteristic);
		}
	}
	auto crossing = [](const int &a, const int &b) -> bool {
		int A = 0, B = 0, AB = 0;
		each(characteristics,sub_populations) {
			bool has_a = false, has_b = false;
			each(characteristic,characteristics) {
				has_a |= characteristic == all_characteristics[a];
				has_b |= characteristic == all_characteristics[b];
			}
			if (has_a && has_b) ++AB;
			else if (has_a) ++A;
			else if (has_b) ++B;
		}
		return AB > 0 && A > 0 && B > 0;
	};
	bool ok = true;
	F0R(a,sz(all_characteristics)) FOR(b,a+1,sz(all_characteristics)) {
		ok &= !crossing(a,b);
	}
	cout << (ok? yes : no);
	return 0;
}
//http://www.usaco.org/index.php?page=viewproblem2&cpid=941
//http://www.usaco.org/current/data/sol_evolution_bronze_open19.html