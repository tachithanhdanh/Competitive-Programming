#include <bits/stdc++.h>
using namespace std;

//variables used for the current problem
int n,m,a[151],b[151],color[101]; bool ok;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("revegetate.in", "r", stdin); 
	freopen("revegetate.out", "w", stdout);
	//Thanks Professor Brian Dean: http://www.usaco.org/current/data/sol_revegetate_bronze_feb19.html
	//http://www.usaco.org/index.php?page=viewproblem2&cpid=916
	cin >> n >> m;
	for (int i=0;i<m;++i){
		cin >> a[i] >> b[i];
		if (a[i]>b[i]) swap(a[i],b[i]);
	}
	for (int i=1;i<=n;++i){
		int g;
		for (g=1;g<=4;++g){
			ok=true;
			for (int j=0; j<m; j++) if (b[j] == i && color[a[j]] == g) ok = false;
      		if (ok) break;
		}
		color[i]=g;
	}
	for (int i=1;i<=n;++i) cout << color[i];
	return 0;
}
