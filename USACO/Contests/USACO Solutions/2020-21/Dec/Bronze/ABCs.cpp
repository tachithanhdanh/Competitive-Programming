#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define endl "\n"
#define all(x) begin(x), end(x)

using ll = long long;

vector<ll> n(7); bool check[4],flag;

void solve(){
	for (int i=0;i<7;++i){
		cin >> n[i];
	}
	sort(all(n));
	do{
		memset(check,false,sizeof(check));
		flag=true;
		check[0]= n[3]==(n[0]+n[1]);
		check[1]= n[4]==(n[2]+n[1]);
		check[2]= n[5]==(n[0]+n[2]);
		check[3]= n[6]==(n[0]+n[1]+n[2]);
		for (int i=0;i<4;++i){
			flag = check[i] && flag;
		}
		if (flag){
			sort(n.begin(),n.begin()+3);
			cout << n[0] << " " << n[1] << " " << n[2]; return;
		}
	} while (next_permutation(all(n)));
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
