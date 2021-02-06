#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	int x[5],y[5];
	for (int i=1;i<=4;++i) {
		cin >> x[i] >> y[i];
	} 
	if (x[4]>=x[2] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1]) { // Case 1
		cout << 0;
	}
	else if (x[3]<=x[1] && y[3]<=y[1] && y[4]>y[1] && x[4]>=x[2]) { // Case 2
		cout << (x[2]-x[1])*(y[2]-y[4]);
	}
	else if (y[3]<y[2] && x[3]<=x[1] && y[4]>=y[2] && x[4]>=x[2]) { // Case 3
		cout << (x[2]-x[1])*(y[3]-y[1]);
	}
	else if (x[4]>x[1] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1]) { // Case 4
		cout << (x[2]-x[4])*(y[2]-y[1]);
	}
	else if (x[3]<x[2] && x[4]>=x[2] && y[4]>=y[2] && y[3]<=x[1]) { // Case 5
		cout << (x[3]-x[1])*(y[2]-y[1]);
	}
	else cout << (x[2]-x[1])*(y[2]-y[1]); // Case 6 and the corner case
	return 0;
}