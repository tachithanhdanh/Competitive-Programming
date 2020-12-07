#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

#define end "\n"

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else{
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
		freopen("error.err","w",stderr);
	}
	return;
}

int n,k,a[15][25],cnt,pos1,pos2,ans; 

void solve(){
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
	return;
}

int main(){
	string name="gymnastics";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}