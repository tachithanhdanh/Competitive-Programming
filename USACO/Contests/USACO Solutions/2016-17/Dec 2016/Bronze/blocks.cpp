#include <bits/stdc++.h>
using namespace std;

int n,ans[26],cnt[26]; vector<vector<string>> vs(100,vector<string>(2,"")); string s;

void dfs(int i){
	for (int j=0;j<2;++j){
		for (int k=0;k<vs[i][j].size();++k){ 
			++cnt[(vs[i][j][k])-'a'];
		}
		if (i==n-1){
			for (int m=0;m<26;++m){
				ans[m]=max(ans[m],cnt[m]);
			}
		}
		else dfs(i+1);
		for (int k=0;k<vs[i][j].size();++k){ 
			--cnt[(vs[i][j][k])-'a'];
		}
	}
}

void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<n;++i){
		for (int j=0;j<2;++j){
			cin >> vs[i][j];
		}
	}
	dfs(0);
	for (int i=0;i<26;++i){
		cout << ans[i] << '\n';
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("blocks.in", "r", stdin); 
	freopen("blocks.out", "w", stdout); 
	solve();
	return 0;
}