#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

#define endl "\n"

void setIO(string name=""){
	ios::sync_with_stdio(0); cin.tie(0);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else{
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
		freopen("error.err","w",stderr);
	}
}

int n,m,ans; char plain[505][55],spotty[505][55],ch; 
bool flag[55][55][55]; //char a1,b1,c1,a2,b2,c2;

void solve(){
	//works in O((n^2)*(M^3))
	//TLE
	cin >> n >> m; 
	//scanf("%d%d",&n,&m);
	//printf("%d%d",n,m);
	scanf("%c",ch);	
	for (int i=0;i<n;++i){
		//scanf("%c",ch);
		for (int j=0;j<m;++j){
			cin >> spotty[i][j];
			//scanf("%c",&spotty[i][j]);
		}
	}
	for (int i=0;i<n;++i){
		//scanf("%c",ch);
		for (int j=0;j<m;++j){
			cin >> plain[i][j];
			//scanf("%c",ch);
			//scanf("%c",&plain[i][j]);
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			for (int k=0;k<m;++k){
				for (int o=k+1;o<m;++o){
					for (int p=o+1;p<m;++p){
						if(flag[k][o][p]) continue; 
						/*
						a1=spotty[i][k];
						b1=spotty[i][o];
						c1=spotty[i][p];
						a2=plain[j][k];
						b2=plain[j][o];
						c2=plain[j][p];
						*/
						if (spotty[i][k]==plain[j][k] && spotty[i][o]==plain[j][o] && spotty[i][p]==plain[j][p]){
							flag[k][o][p]=true;
						}
					}
				}	
			}
		}
	}
	for (int i=0;i<m;++i){
		for (int j=i+1;j<m;++j){
			for (int k=j+1;k<m;++k){
				ans+=(!flag[i][j][k]);
			}
		}
	}
	cout << ans << endl;
	//printf("\n%d\n",ans);
	return;
}

int main(){
	string name="cownomics";
	setIO(name);
	solve();
	//cerr << (float)clock()/CLOCKS_PER_SEC;
	return 0;
}