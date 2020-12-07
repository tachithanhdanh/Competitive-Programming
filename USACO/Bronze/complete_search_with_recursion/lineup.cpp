#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;
 
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;
using ld = long double;
 
#define endl "\n" 
#define hash_set unordered_set 
#define hash_map unordered_map
#define all(x) begin(x), end(x) 
#define rall(x) (x).rbegin(), (x).end()
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define mtp make_tuple

void setIO(string name=""){
	ios::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()){
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
	else {
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	}
	return;
}

vector<string> cows= { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<vector<string>> ans;
vector<pair<string,string>> cons;
string cow1,bs,cow2;
int n; bool flag;

bool check(){
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
}

void solve(){
	cin >> n;
	for (int i=0;i<n;++i){
		cin >> cow1 >> bs >> bs >> bs >> bs >> cow2;
		cons.pb(mp(cow1,cow2));
	}
	sort(all(cows));
	for (string s : cows){
		cerr <<s << endl;
	}
	do {
		if (check()){
			ans.pb(cows);
		}
	} while(next_permutation(all(cows)));
	sort(all(ans));
	for (string cow : ans[0]){
		cout << cow << endl;
	}
	return;
}

int main(){
	string name="lineup";
	setIO(name);
	solve();
	cerr << "time taken: " << (float)clock()/CLOCKS_PER_SEC << endl;
	return 0;
}