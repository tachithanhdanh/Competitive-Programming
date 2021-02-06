#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> check(2050,vector<bool>(2050,false));
int ans,x1,x2,y11,y2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	for (int i=0;i<3;++i){
		cin >> x1 >> y11 >> x2 >> y2;
		x1+=1000; x2+=1000; y11+=1000; y2+=1000;
		for (int x=x1;x<x2;++x){
			for (int y=y11;y<y2;++y){
				if (i<2) check[x][y]=true;
				else check[x][y]=false;
			}
		}
	}
	for (int i=0;i<2050;++i){
		for (int j=0;j<2050;++j){
			ans+=check[i][j];
		}
	}
	cout << ans;
	return 0;
}
 
