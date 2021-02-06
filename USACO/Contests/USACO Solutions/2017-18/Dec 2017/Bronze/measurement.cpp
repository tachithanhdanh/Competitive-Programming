#include <bits/stdc++.h>
using namespace std;
 
vector<pair<string,int>> cows;
vector<string> cow_name= {"Bessie", "Elsie", "Mildred"};
vector<tuple<int,string,int>> data;
int ans,n,day,milk; string name; char ch;
vector<string> top,pretop;
string cow;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("measurement.in","r",stdin);
	freopen("measurement.out","w",stdout);
	//Your solution starts here.
	for (int i=0;i<3;++i){
		cows.push_back(make_pair(cow_name[i],7));
	}
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> day >> name >> ch >> milk;
		if (ch=='-') milk-=2*milk;
		data.push_back(make_tuple(day,name,milk));
	}
	sort(data.begin(),data.end());
	top=cow_name;
	for (auto x :data){
		cow=get<1>(x);
		milk=-1;
		pretop=top; top.clear();
		for (int i=0;i<3;++i){
			if (cows[i].first==cow){
				cows[i].second+=get<2>(x);
			}
		}
		for (int i=0;i<3;++i){
			if (cows[i].second>milk){
				milk=cows[i].second;
			}
		}
		for (int i=0;i<3;++i){
			if (cows[i].second==milk){
				top.push_back(cows[i].first);
			}
		}
		if (top!=pretop) ++ans;
	}
	cout << ans;
	return 0;
}
 
