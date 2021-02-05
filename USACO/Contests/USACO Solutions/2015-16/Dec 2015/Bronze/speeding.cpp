#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int n,m,a[105],b[105],ans,c,d,e;

void solve(){ //Your solution starts here.
	cin >> n >>m; e=1;
	for (int i=0;i<n;++i){
		cin >> c >> d;
		for (int j=e;j<e+c;++j){
			a[j]=d;
		}
		e+=c;
	}
	e=1;
	for (int i=0;i<m;++i){
		cin >> c >> d;
		for (int j=e;j<e+c;++j){
			b[j]=d;
		}
		e+=c;
	}
	for (int i=1;i<=100;++i){
		ans=max(ans,b[i]-a[i]);
	}
	cout << ans;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("speeding.in", "r", stdin);  
	freopen("speeding.out", "w", stdout); 
	solve(); 
	return 0;
}