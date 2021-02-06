#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n,x,y; vector<pair<int,int>> v; ll a,b,area,ans;

int main(){
	string name="triangles";
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
				if (v[i].f==v[j].f && v[i].s==v[k].s){
					a=abs(v[i].s-v[j].s);
					b=abs(v[i].f-v[k].f);
					area=a*b;
				}
				ans=max(area,ans);
			}
		}
	}
	cout << ans;
	return 0;
}
 
