#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<string> cows= { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<vector<string>> ans;
vector<pair<string,string>> cons;
string cow1,bs,cow2;
int n; bool flag;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lineup.in", "r", stdin); 
	freopen("lineup.out", "w", stdout);
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> cow1 >> bs >> bs >> bs >> bs >> cow2;
		cons.pb(mp(cow1,cow2));
	}
	sort(all(cows));
	auto check = []() -> bool
	{
		for (pair<string,string> cow : cons){
			cow1=cow.f; cow2=cow.s;
			flag=false;
			for (int i=0;i<2;++i){
				for(int i=1;i<7;++i){
					if (cows[i]==cow1){
						if (cows[i-1]==cow2 || cows[i+1]==cow2){
							flag=true;
						}
					}
				}
				swap(cow1,cow2);
			}
			if (!flag) return flag;
		}
		return true;
	};
	do {
		if (check()){
			ans.pb(cows);
		}
	} while(next_permutation(all(cows)));
	sort(all(ans));
	for (string cow : ans[0]){
		cout << cow << endl;
	}
	return 0;
}