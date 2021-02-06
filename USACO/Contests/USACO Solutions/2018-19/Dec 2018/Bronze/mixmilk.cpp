#include <bits/stdc++.h>
using namespace std;
 
int c[3],m[3],tmp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("mixmilk.in", "r", stdin);  
	freopen("mixmilk.out", "w", stdout); 
	//Your solution starts here.
	for (int i=0;i<3;++i){
		cin >> c[i] >> m[i];
	}
	for (int i=0;i<100;++i){
		if (i%3==0){
			tmp=min(m[0],c[1]-m[1]);
			m[0]-=tmp;
			m[1]+=tmp;
		}
		else if (i%3==1){
			tmp=min(m[1],c[2]-m[2]);
			m[1]-=tmp;
			m[2]+=tmp;
		}
		else {
			tmp=min(m[2],c[0]-m[0]);
			m[2]-=tmp;
			m[0]+=tmp;
		}
	}
	cout << m[0] << '\n' << m[1] << '\n' << m[2];
	return 0;
}