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
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	int N; cin >> N;
	vi b(N-1), a(N); each(a,b) cin >> a;
	if (N<=8) {
		iota(all(a),1);
		do {
			bool flag = true;
			F0R(i,N-1) {
				flag &= a[i] + a[i+1] == b[i];
			}
			if (flag) {
				cout << *begin(a);
				FOR(i,1,N) cout << " " << a[i];
				break;
			}
		} while (next_permutation(all(a)));
	}
	else {

		FOR(i,1,N+1) {
			vector<bool> used(N+1);
			a[0] = i; used[i] = true;
			bool flag = true;
			FOR(j,1,N) {
				a[j] = b[j-1] - a[j-1];
				//each(b,a) cout << b << " ";
				//cout << endl;
				if (a[j] <= 0 || a[i] > N || used[a[j]]) {
					flag = false; break;
				}
				used[a[j]] = true;
			}
			if (flag) {
				cout << *begin(a);
				FOR(j,1,N) cout << " " << a[j];
				break;
			}
		}
	}
	return 0;
}
