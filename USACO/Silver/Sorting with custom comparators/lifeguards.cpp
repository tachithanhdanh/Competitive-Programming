#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO (string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem

int main() {
	setIO("lifeguards");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N;
	cin >> N;
	vector<pi> shifts(N);
	for (pi& shift : shifts) cin >> shift.f >> shift.s;
	sort(all(shifts));
	shifts.pb(mp(MOD,0));
	int total = 0, left = 0, right = 0;
	for (pi& shift : shifts) {
		if (shift.s > right) {
			left = max(shift.f,right);
			right = shift.s;
			total += right - left;
		}
	}
	right = 0;
	int minRemoved = MOD;
	for (int i = 0; i < N; ++i) {
		int TimeRemoved = min(shifts[i].s,shifts[i+1].f) - max(right,shifts[i].f);
		right = max(right, shifts[i].s);
		minRemoved = min(minRemoved,TimeRemoved);
	}
	cout << total - max(minRemoved,0);
	return 0;
}
