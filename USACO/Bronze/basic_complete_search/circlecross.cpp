#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

#define endl "\n"

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifndef ONLINE_JUDGE 
		freopen("input.in", "r", stdin); 
		freopen("error.err", "w", stderr); 
		freopen("output.out", "w", stdout); 
		#endif 
	}
	return;
}

string s; char a,b; int ai,aj,bi,bj,ans,n;

void solve(){ //Your solution starts here.
	cin >> s; n=s.size();
	for (int i=0;i<26;++i){
		for (int j=i+1;j<26;++j){
			a=char('A'+i); b=char('A'+j);
			//cerr << a << " " << b << endl;
			for (int j=0;j<2;++j){
				ai=aj=bi=bj=-1;
				for (int m=0;m<n;++m){
					if (a==s[m]){
						if (ai==-1){
							ai=m;
						}
						else aj=m;
					}
					else if (b==s[m]){
						if (bi==-1){
							bi=m;
						}
						else bj=m;
					}
				}
				if (ai<bi && bi<aj && aj<bj) {
					++ans;
					//cerr << s[ai] << " " << s[aj] << " " << s[bi] << " " << s[bj] << endl;
				}
				swap(a,b);
			}
		}
	}
	cout << ans << endl;
	return;
}
//Thanks Benjamin Qi for writing these tips.
// you should actually read the stuff below
// read!read!read!read!read!read!read!read!read!
// ll vs. int!
 
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/
int main(){
	string name="circlecross";
	setIO(name);
	//cout.tie(NULL);
	//cin >> t;
	//while (t--)
	solve();
	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC <<" secs"<<endl; 
	return 0;
}