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
	int N; ll X;
	cin >> N >> X;
	vector<ll> T(N); each(t,T) cin >> t;
	if (N == 1)
	{
		if (*begin(T) == X) cout << 1;
		else cout << 0;
		return 0;
	}
	auto possible_sums = [&](vector<ll>::iterator l, vector<ll>::iterator r) {
		int n = r - l;
		vector<ll> sums(1<<n);
		F0R(mask,(1<<n)) {
			ll sum = 0;
			F0R(i,n) if (mask & (1<<i)) sum += l[i];
			sums[mask] = sum;
		}
		sort(all(sums));
		return sums;
	};
	vector<ll> left_partition = possible_sums(begin(T), begin(T)+N/2);
	vector<ll> right_partition = possible_sums(begin(T)+N/2, end(T));
	ll ans = 0;
	each(sum,left_partition) {
		ll companion = X - sum;
		auto left_bound = lower_bound(right_partition.begin(), right_partition.end(), companion);
		auto right_bound = upper_bound(right_partition.begin(), right_partition.end(), companion);
		ans += right_bound - left_bound;
	}
	cout << ans << endl;
	return 0;
}
