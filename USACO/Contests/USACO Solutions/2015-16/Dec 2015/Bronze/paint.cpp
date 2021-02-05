#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

using si = short int;

si a,b,c,d;
//http://www.usaco.org/index.php?page=viewproblem2&cpid=567

void solve(){
	cin >> a >> b >> c >> d;
	if (b<c || d<a) cout << (b-a)+(d-c);
	else cout << max(b,d)-min(a,c);
	return;
}

int main(){
	//Read input from STDIN, then print the output to STDOUT.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	solve();
	return 0;
}

