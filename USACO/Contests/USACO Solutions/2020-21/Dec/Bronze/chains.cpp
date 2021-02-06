#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define endl "\n"
#define all(x) begin(x), end(x)

using ll = long long;

int n,p[150],a,sum,ans;

void solve(){
	//cout << ans << endl;
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> p[i];
		p[i]+=p[i-1];
	}
	p[n+1]=p[n];
	for (int i=1;i<=n;++i){
		for (int j=i;j<=n;++j){
			sum=p[j]-p[i-1];
			a=sum/(j-i+1);
			//cout << sum << " ";
			//cout << a*(j-i+1) << endl;
			if (a*(j-i+1)!=sum) continue;
			for (int k=i;k<=j;++k){
				if (p[k]-p[k-1]==a) {
					//cout << p[k]-p[k-1] << endl;
					++ans;
					break;
				}
			}
			
		}
		//cout << "a" << endl;
	}
	cout << ans << endl;
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
