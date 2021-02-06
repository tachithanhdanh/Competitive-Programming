#include <bits/stdc++.h>
using namespace std;
 
int n,d; 
vector<int> a(110),b,c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("shuffle.in", "r", stdin); 
	freopen("shuffle.out", "w", stdout); 
	//Your solution starts here.
	cin >> n; b=a; c=a;
	for (int i=1;i<=n;++i){
		cin >> a[i];
	}
	for (int i=1;i<=n;++i){
		cin >> b[i];
	}
	for (int i=0;i<3;++i){
		for (int j=1;j<=n;++j){
			c[j]=b[a[j]];
		}
		b=c;
	}
	for (int i=1;i<=n;++i){
		cout << b[i] << '\n';
	}
	return 0;
}