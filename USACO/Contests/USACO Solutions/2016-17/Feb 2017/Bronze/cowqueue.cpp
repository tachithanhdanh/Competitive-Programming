#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cowqueue.in", "r", stdin); 
	freopen("cowqueue.out", "w", stdout); 
	//Your solution starts here.
	int n;
	cin >> n;
	vector<pair<long long, long long>> v(n); 
	for (int i=0;i<n;++i){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end());
	long long ans=v.front().first+v.front().second;
	for (int i=1;i<n;++i){
		if (ans>=v[i].first){
			ans+=v[i].second;
		}
		else ans=v[i].first+v[i].second;
	}
	cout << ans;
	return 0;
}