#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

int n,x,y; 
vector<pair<int,int>> v; 
ll a,b,area,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("triangles.in", "r", stdin); 
	freopen("triangles.out", "w", stdout); 
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> x >> y;
		v.pb(mp(x,y));
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			for (int k=0;k<n;++k){
				if (v[i].X == v[j].X && v[i].Y == v[k].Y){
					a=abs(v[i].Y-v[j].Y);
					b=abs(v[i].X-v[k].X);
					area=a*b;
				}
				ans=max(area,ans);
			}
		}
	}
	cout << ans;
	return 0;
}
 
