#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mtp make_tuple

int n,t,a,b,c,turns[101],k,mink=500,maxk,numcow; bool patientzero[101];
string cows,test; vector<tuple<int,int,int>> v;
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1037
//http://www.usaco.org/current/data/sol_tracing_bronze_open20.html
//https://usaco.guide/bronze/intro-complete

int main(){
	string name="tracing";
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("tracing.in", "r", stdin); 
	freopen("tracing.out", "w", stdout);
	//Your solution starts here.
	cin >> n >> t;
	cin >> cows;
	for (int i=0;i<t;++i){
		cin >> a >> b >> c;
		--b; --c;
		v.pb(mtp(a,b,c)); 
	}
	sort(all(v)); test=cows;
	for (int i=0;i<n;++i){
		if (cows[i]=='1'){
			k=0;
			while(k<=t){
				fill(all(test),'0');
				test[i]='1';
				fill(all(turns),k);
				for (int j=0;j<t;++j){
					b=get<1>(v[j]); c=get<2>(v[j]);
					if (test[b]=='1' && turns[b] && test[c]=='0'){
						--turns[b]; test[c]='1';
					}
					else if (test[c]=='1' && turns[c] && test[b]=='0'){
						--turns[c]; test[b]='1';
					}
					else if (test[b]=='1' && test[c]=='1'){
						if (turns[c]) --turns[c];
						if (turns[b]) --turns[b];
					}
				}
				if (test==cows) {
					if (mink>k) mink=k;
					if (maxk<k) maxk=k;
					patientzero[i]=true;
				}
				++k;
			}
		}
	}
	for (int i=0;i<101;++i){
		numcow+=patientzero[i];
	}
	cout << numcow << " " << mink << " ";
	if (maxk>=t){
		cout << "Infinity";
	}
	else cout << maxk;
	return 0;
}
 
