#include <bits/stdc++.h>
using namespace std;

int n,i_index,j_index,ans; bool cows[11][11],flag; char ch;

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			cin >> ch;
			cows[i][j]= ch == '1';
		}
	}
	for (int i=n-1;i>-1;--i){
		for (int j=n-1;j>-1;--j){
			if (cows[i][j]){
				++ans;
				for (int a=0;a<=i;++a){
					for (int b=0;b<=j;++b){
						cows[a][b]=!cows[a][b];
					}
				}
			}
		}
	}
	cout << ans;
	return;
}

int main(){
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	solve();
	return 0;
}