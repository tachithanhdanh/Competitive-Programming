#include <bits/stdc++.h>
using namespace std;

int n,milk,sec,cnt; map<string,int> mp; string cow;
string cowlist[]={"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
 
void solve(){ //Your solution starts here.
	cin >> n;
	for (int i=0;i<7;++i){
		mp[cowlist[i]]=0;
	}
	while (n--){
		cin >> cow >> milk;
		mp[cow]+=milk;
	}
	milk=1e5;
	for (pair<string,int> p : mp){
		milk=min(milk,p.second);
	}
	sec=1e5;
	for (auto p : mp){
		if (p.second<sec && p.second!=milk){
			sec=p.second;
		}
	}
	if (sec==(int)1e5){
		cout << "Tie" << endl; return;
	}
	for (auto p: mp){
		if (p.second==sec){
			cow=p.first;
			++cnt;
		}
	}
	if (cnt>1) cout << "Tie" << endl;
	else {
		cout << cow;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("notlast.in","r",stdin);
	freopen("notlast.out","w",stdout);
	solve();
	return 0;
}
 
