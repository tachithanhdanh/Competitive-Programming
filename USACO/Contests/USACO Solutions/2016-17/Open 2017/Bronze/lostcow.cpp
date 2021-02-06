#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n" 
#define ll long long  
 
int x,y,a,b,z=1,ans,cnt=1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lostcow.in", "r", stdin); 
	freopen("lostcow.out", "w", stdout); 
	cin >> x >> y;
	a=x;
	while(a!=y){
		if (cnt&1){
			b=x+z;
		}
		else b=x-z;
		z*=2; ++cnt;
		while(a!=b){
			if (a<b) ++a;
			else --a;
			++ans; 
			if (a==y){
				cout << ans; return 0;
			}
		}
	}
	return 0;
}