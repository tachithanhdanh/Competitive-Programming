#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int N;
long long ans = 0;
vector<pair<int,int>> v;

void tri() {
	sort(v.begin(), v.end());
	vector<pair<int,int>> lef(N), rig(N);
	auto comb = [](pair<int,int> a, int b) -> pair<int,int> {
		return make_pair(min(a.first,b),max(a.second,b));
	};
	lef[0] = make_pair(v[0].second,v[0].second);
	for (int i = 1; i < N; ++i) lef[i] = comb(lef[i-1],v[i].second);
	rig[N-1] = make_pair(v[N-1].second,v[N-1].second);
	for (int i = N - 2; i >= 0; --i) rig[i] = comb(rig[i+1],v[i].second);
	long long area = 1LL*(v.back().first-v.front().first)*(lef.back().second-lef.back().first);
	long long best = INF;
	for (int i = 0; i < N - 1; ++i)
		best = min(best,1LL*(v[i].first-v[0].first)*(lef[i].second-lef[i].first)
			+1LL*(v.back().first-v[i+1].first)*(rig[i+1].second-rig[i+1].first));
	ans = max(ans,area-best);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	cin >> N;
	v.resize(N);
	for (pair<int,int>& t : v) cin >> t.first >> t.second;
	tri();
	for (pair<int,int>& t : v) swap(t.first,t.second);
	tri();
	cout << ans;
	return 0;
}
