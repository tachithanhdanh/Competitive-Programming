#include<bits/stdc++.h> 
using namespace std; 

int n,a[105],t,cnt,ans=1,dif; bool flag;
vector<bool> check((int)1e9+7,false); vector<int> v,vv;

void solve(){ //Your solution starts here.
	// 5 1 2 4 7 11
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a[i];
	}
	for (int i=0;i<n;++i){
		t=0; cnt=0; flag=true;
		for (int j=0;j<n;++j){
			check[a[j]]=false;
		}
		v.clear(); vv.clear(); v.push_back(a[i]);
		while (flag){
			flag=false;
			for (int j=0;j<n;++j){
				dif=INT_MAX;
				for (int x : v){
					dif=min(dif,abs(x-a[j]));
				}
				if (dif<=t && !check[a[j]]){
					++cnt; check[a[j]]=true; flag=true;
					vv.push_back(a[j]);
				}
			}
			v=vv; vv.clear(); ++t;
		}
		ans=max(ans,cnt); 
	}
	cout << ans;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	solve();
	return 0;
}
 
