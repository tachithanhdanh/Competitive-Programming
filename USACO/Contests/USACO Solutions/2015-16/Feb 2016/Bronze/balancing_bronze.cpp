#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n,x[110],y[110],a,b,section[5],ans=INT_MAX,cnt[4]; vector<pair<int,int>> v; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("balancing.in", "r", stdin); 
	freopen("balancing.out", "w", stdout);
	//Your solution starts here.
	cin >> n >> b;
	for (int i=0;i<n;++i){
		cin >> x[i] >> y[i];
		v.pb(mp(x[i],y[i]));
	}
	auto find_ans = []() -> int
	{
		int ans=0;
		memset(section,0,sizeof(section));
		for (pair<int,int> p : v){
			if (p.f<a && p.s>b){
				++section[1];
			}
			else if (p.f>a && p.s>b){
				++section[2];
			}
			else if (p.f>a && p.s<b){
				++section[3];
			}
			else if (p.f<a && p.s<b){
				++section[4];
			}
		}
		for (int i=0;i<5;++i){
			ans=max(ans,section[i]);
		}
		return ans;
	};
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			a=x[i]+1; b=y[j]+1;
			cnt[0]=find_ans();
			a=x[i]-1; b=y[j]+1;
			cnt[1]=find_ans();
			a=x[i]+1; b=y[j]-1;
			cnt[2]=find_ans();
			a=x[i]-1; b=y[j]-1;
			cnt[3]=find_ans();
			for (int i=0;i<4;++i){
				ans=min(ans,cnt[i]);
			}
		}
	}
	cout << ans;
	return 0;
}