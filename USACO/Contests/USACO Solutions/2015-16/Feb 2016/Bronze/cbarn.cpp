#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
 using namespace std;
 
int n,a[1010],ans=INT_MAX,total;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cbarn.in", "r", stdin); 
	freopen("cbarn.out", "w", stdout); 
	//Your solution starts here.
	cin >> n;
	for (int i=1;i<=n;++i){
		cin >> a[i];
	}
	for (int i=1;i<=n;++i){
		total=0;
		for (int j=i+1;j<=n;++j){
			total+=a[j]*(j-i);
		}
		for (int j=i-1;j>=1;--j){
			total+=a[j]*(n-i+j);
		}
		ans=min(ans,total);
	}
	cout << ans;
	return 0;
}
