#include <bits/stdc++.h>
using namespace std;
 
short int n,ans[4],a,b,g; vector<vector<bool>> vb(4,vector<bool>(4,false));

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("shell.in", "r", stdin);  
	freopen("shell.out", "w", stdout); 
	//Your solution starts here. 
	vb[1][1]=true; vb[2][2]=true; vb[3][3]=true;
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> a >> b >> g;
		for (int i=1;i<4;++i){
			swap(vb[i][a],vb[i][b]);
			if (vb[i][g]) ++ans[i];
		}
	}
	sort(ans,ans+4);
	cout << ans[3];
	return 0;
}