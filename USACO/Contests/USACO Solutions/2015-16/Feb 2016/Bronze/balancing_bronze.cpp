#include <bits/stdc++.h>
using namespace std;

using ll = long long;
 
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

void setIO(string name =""){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		#ifndef ONLINE_JUDGE 
		freopen("input.txt", "r", stdin); 
		freopen("error.txt", "w", stderr); 
		freopen("output.txt", "w", stdout); 
		#endif 
	}
	return;
}

int n,x[110],y[110],a,b,section[5],ans=INT_MAX,cnt[4]; vector<pair<int,int>> v; 

int find_ans(){
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
}

void solve(){ //Your solution starts here.
	cin >> n >> b;
	for (int i=0;i<n;++i){
		cin >> x[i] >> y[i];
		v.pb(mp(x[i],y[i]));
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			a=x[i]+1; b=y[j]+1;
			cnt[0]=find_ans();
			//cerr << m << endl;
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
	cout << ans << endl;
	return;
}
int main(){
	string name="balancing";
	setIO(name);
	solve();
	return 0;
}
 
