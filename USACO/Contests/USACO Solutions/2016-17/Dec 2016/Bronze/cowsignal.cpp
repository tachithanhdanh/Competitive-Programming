#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cowsignal.in","r",stdin);
	freopen("cowsignal.out","w",stdout);
	int m,n,k; char c[10][10];
	cin >> m >> n >> k;
	for (int i=0;i<m;++i){
		for (int j=0;j<n;++j){
			cin >> c[i][j];
		}
	}
	for (int i=0;i<m;++i){
		for (int o=0;o<k;++o){
			for(int j=0;j<n;++j){
				for (int p=0;p<k;++p){
					cout << c[i][j];
				}
			}
			cout << '\n';
		}
	}
	return 0;
}