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

int n,m,ans,s[505][55],p[505][55],a[64]; 
char plain[505][55],spotty[505][55]; 

bool check_set(int i1,int i2,int i3){
	bool good=true;
	for (int i=0;i<n;++i){
		a[s[i][i1]*16+s[i][i2]*4+s[i][i3]]=1;
	}
	for (int i=0;i<n;++i){
		if(a[p[i][i1]*16+p[i][i2]*4+p[i][i3]]) good=false;
	} 
	for (int i=0;i<n;++i){
		a[s[i][i1]*16+s[i][i2]*4+s[i][i3]]=0;
	}
	return good;
}

void solve(){
	//works in O((n)*(M^3))
	//near to TLE but somehow passed
	//http://www.usaco.org/current/data/sol_cownomics_silver_open17.html
	cin >> n >> m; 	
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			cin >> spotty[i][j];
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			cin >> plain[i][j];
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if(spotty[i][j]=='A') s[i][j]=0;
			if(spotty[i][j]=='C') s[i][j]=1;
			if(spotty[i][j]=='G') s[i][j]=2;
			if(spotty[i][j]=='T') s[i][j]=3;
			if(plain[i][j]=='A') p[i][j]=0;
			if(plain[i][j]=='C') p[i][j]=1;
			if(plain[i][j]=='G') p[i][j]=2;
			if(plain[i][j]=='T') p[i][j]=3;
		}
	}
	for (int k=0;k<m;++k){
		for (int o=k+1;o<m;++o){
			for (int p=o+1;p<m;++p){
				if (check_set(k,o,p)) ++ans;
			}
		}
	}
	cout << ans << endl;
	return;
}

int main(){
	string name="cownomics";
	setIO(name);
	solve();
	//cerr << (float)clock()/CLOCKS_PER_SEC;
	return 0;
}