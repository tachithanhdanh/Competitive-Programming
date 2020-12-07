#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

#define endl "\n"

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if(name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else{
		freopen("input.in","r",stdin);
		freopen("output.out","w",stdout);
		freopen("error.err","w",stderr);
	}
}

int a,b,c,ans,n; 

void solve(){
	cin >> a >> b >> c;
	for (int i=0;i<1005;++i){
		if (a*i>c) break;
		for (int j=0;j<1005;++j){
			n=a*i+b*j;
			if (n>c) break;
			ans=max(ans,n);
		}
	}
	cout << ans << endl;
	return;
}

int main(){
	string s="pails";
	setIO(s);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}