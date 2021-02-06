#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define end "\n"

int n,k,a[15][25],cnt,pos1,pos2,ans; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("gymnastics.in", "r", stdin); 
	freopen("gymnastics.out", "w", stdout);
	cin >> k >> n;
	for (int i=1;i<=k;++i){
		for (int j=1;j<=n;++j){
			cin >> a[i][j];
		}
	}
	if (k==1){
		cout << (n*(n-1))/2 << endl; return;
	}
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			cnt=0;
			for (int m=1;m<=k;++m){
				for (int q=1;q<=n;++q){
					if (a[m][q]==i){
						pos1=q;
					}
					else if (a[m][q]==j){
						pos2=q;
					}
				}
				if (pos1<pos2) ++cnt;
			}
			if (cnt==0 || cnt==k) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}