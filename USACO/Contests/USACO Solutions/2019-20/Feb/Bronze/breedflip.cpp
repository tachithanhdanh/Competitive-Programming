#include <bits/stdc++.h>
using namespace std;

int n,cnt; string a,b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("breedflip.in", "r", stdin); 
	freopen("breedflip.out", "w", stdout);
	cin >> n >> a >> b;
	for (int i=0;i<n;++i){
		if (a[i]!=b[i]){
			++cnt;
			while (a[i]!=b[i]){
				++i;
			}
			--i;
		}
	}
	cout << cnt;
	return 0;
}