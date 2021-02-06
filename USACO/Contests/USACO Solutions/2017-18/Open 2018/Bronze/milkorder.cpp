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
	freopen("milkorder.in","r",stdin);
	freopen("milkorder.out","w",stdout);
	//Problem solved by applying the Greedy technique
	//Better than the official analysis (http://www.usaco.org/current/data/sol_milkorder_bronze_open18.html)
	//Time Complexity O(N*M)
	int N, M, K; bool is_one = false;
	cin >> N >> M >> K;
	vi pos(N+1),order(M),cow(N+1);
	each(m,order) {
		cin >> m;
		is_one |= m == 1;
	}
	F0R(i,K) {
		int a, b;
		cin >> a >> b;
		if (a==1) {
			cout << b; return 0;
		}
		pos[b] = a;
		cow[a] = b;
	}
	if (is_one) {
		int pre = 0;
		if (cow[order[0]]) pre = cow[order[0]];
		F0R(i,M) {
			if (!cow[order[i]]) {
				FOR(j,pre+1,N+1) {
					if (!pos[j]) {
						pos[j] = order[i]; pre = cow[order[i]] = j; break;
					}
				}
			}
		else pre = cow[order[i]];
		}
		FOR(i,1,N+1) {
			if (pos[i]==1) {
				cout << i; return 0;
			}
		}
	}
	else {
		int pre = N+1;
		if (cow[order[M-1]]) pre = cow[order[M-1]];
		R0F(i,M) {
			if (!cow[order[i]]) {
				ROF(j,1,pre) {
					if (!pos[j]) {
						pos[j] = order[i]; pre = cow[order[i]] = j; break;
					}
				}
			}
			else pre = cow[order[i]];
		}
		FOR(i,1,N+1) if(!pos[i]) {
			cout << i; break;
		}
	}
	return 0;
}
