#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cowsignal.in","r",stdin);
	freopen("cowsignal.out","w",stdout);
	int m,n,k; char c[10][10];
	cin >> m >> n >> k;
	for (si i=0;i<m;++i){
		for (si j=0;j<n;++j){
			cin >> c[i][j];
		}
	}
	for (si i=0;i<m;++i){
		for (si o=0;o<k;++o){
			for(si j=0;j<n;++j){
				for (si p=0;p<k;++p){
					cout << c[i][j];
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
