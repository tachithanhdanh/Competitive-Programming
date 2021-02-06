#include <bits/stdc++.h>
using namespace std;
 
int s,n,ans=INT_MAX,pos1=2000,pos2=2000,step; char d;
int grass[4050][4050];

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> d >> s;
		for (int j=0;j<s;++j){
			if (d=='N') --pos1;
			else if (d=='S') ++pos1;
			else if (d=='E') ++pos2;
			else --pos2; 
			++step;
			if (grass[pos1][pos2]){
				ans=min(ans,step-grass[pos1][pos2]);
			}
			grass[pos1][pos2]=step;
		}
	}
	if (ans==INT_MAX) cout << -1;
	else cout << ans;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("mowing.in", "r", stdin); 
	freopen("mowing.out", "w", stdout); 
	solve();
	return 0;
}
 
