#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

#define endl "\n"
#define all(x) begin(x), end(x)

using ll = long long;

ll n,ans[50],dist[50],a[50][3],dx,dy,d[50],delta; bool pos[50][50]; char ch; bool flag;

void solve(){
	cin >> n;
	//memset(ans,-1,sizeof(ans));
	fill(ans,ans+50,(ll)2e9);
	fill(dist,dist+50,(ll)2e9);
	//v.resize(n);
	for (int i=0;i<n;++i){
		cin >> ch;
		a[i][0]= ch=='N';
		cin >> a[i][1] >> a[i][2];
	}
	/*
	for (int i=0;i<n;++i){
		cout << a[i][0] << " " << a[i][1] << " "  << a[i][2] << endl;
	}
	*/
		for (int i=0;i<n;++i){
		//flag=a[i][0];
		for (int j=0;j<n;++j){
			if (i==j) continue;
			if (a[i][0]==1 && a[j][0]==0){
				if (a[i][1]>a[j][1] && a[i][2]<a[j][2]){
					dx=abs(a[i][1]-a[j][1]);
					dy=abs(a[i][2]-a[j][2]);
					if (dx<dy){
						ans[i]=j;
						pos[i][j]=true;
						dist[i]=min(dist[i],dy);
					}
				}
			}
			else if (a[i][0]==0 && a[j][0]==1){
				if (a[i][1]<a[j][1] && a[i][2]>a[j][2]){
					dx=abs(a[i][1]-a[j][1]);
					dy=abs(a[i][2]-a[j][2]);
					if (dy<dx){
						ans[i]=j;
						pos[i][j]=true;
						dist[i]=min(dist[i],dx);
					}
				}
			}
		}
	}
	
	for (int i=0;i<n;++i){
		if (ans[i]!=2e9){
			if (ans[ans[i]]!=2e9){
				if (a[i][0]==0){
					delta=abs(a[i][2]-a[ans[i]][2]);
					if (delta>dist[ans[ans[i]]]){
						for (int j=0;j<n;++j){
							if (a[j][0]!=a[i][0] && dist[j]>abs(a[i][2]-a[j][2]))
						}
					}
				}
				else{
					delta=abs(a[i][1]-a[i][1]);
				}
			}
		}
	}

	for (int i=0;i<n;++i){
		if (ans[i]==2e9) cout << "Infinity" << endl;
		else cout << ans[i] << endl;
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
