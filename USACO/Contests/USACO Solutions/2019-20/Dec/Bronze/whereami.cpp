#include <bits/stdc++.h>
using namespace std;

int n,pos; string s,ss;
//http://www.usaco.org/current/data/sol_whereami_bronze_dec19.html
//http://www.usaco.org/index.php?page=viewproblem2&cpid=964 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("whereami.in", "r", stdin); 
	freopen("whereami.out", "w", stdout);
	//Your solution starts here.
	cin >> n >> s; ++pos;
	for (int i=0;i<n-pos;++i){
		ss=s.substr(i,pos);
		while (s.find(ss,i+1)!=-1){
			++pos;
			ss=s.substr(i,pos);
		}
	}
	cout << pos;
	return 0;
}
 
