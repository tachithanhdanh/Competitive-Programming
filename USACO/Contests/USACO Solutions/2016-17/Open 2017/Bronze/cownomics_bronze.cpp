#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,ans; 
vector<string> spotty,plain; 
vector<bool> flag(110,true);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("cownomics.in", "r", stdin); 
	freopen("cownomics.out", "w", stdout);
	cin >> n >> m;
	spotty.resize(n); plain=spotty;
	for (string& s: spotty){
		cin >> s;
	}
	for (string& s: plain){
		cin >> s;
	}
	for (int i=0;i<m;++i){
		for (int j=0;j<n;++j){
			for (int k=0;k<n;++k){
				if (spotty[j][i]==plain[k][i]){
					flag[i]=false;
				}
			}
		}
	} 
	for (int i=0;i<m;++i){
		ans+=flag[i];
	}
	cout << ans;
	return 0;
}