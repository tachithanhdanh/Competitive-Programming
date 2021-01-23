#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

#define endl "\n"
#define all(x) begin(x), end(x)

using ll = long long;

bool grid[250][250],flag[50]; int n,a[50][3],cnt[50],x,y; char ch;
vector<pair<int,int>> q; pair<int,int> p;

void solve(){
	cin >> n;
	for (int i=0;i<50;++i) {
		flag[i]=true; cnt[i]=0;
	}
	/*
	for (int i=0;i<250;++i){
		for (int j=0;j<2000;++j){
			grid[i][j]=false;
		}
	}
	*/
	for (int i=0;i<n;++i){
		cin >> ch;
		a[i][0]= ch=='N';
		cin >> a[i][1] >> a[i][2];
	}
	for (int i=0;i<150;++i){
		for (int j=0;j<n;++j){
			if (flag[j]){
				x=a[j][1]; y=a[j][2];
				if (a[j][0]) {
					if (!grid[x][y+i]){
						++cnt[j]; q.push_back(make_pair(x,y+i));
					}
					else flag[j]=false;
				}
				else{
					if (!grid[x+i][y]){
						++cnt[j]; q.push_back(make_pair(x+i,y));
					}
					else flag[j]=false;
				}
			}
		}
		while (!q.empty()){
					p=q.back();
					q.pop_back();
					grid[p.first][p.second]=true;
				}
	}
	for (int i=0;i<n;++i){
		if (cnt[i]>101){
			cout << "Infinity";
		}
		else cout << cnt[i];
		cout << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  	#ifdef LOCAL
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout);
  	#endif
    solve();
}
