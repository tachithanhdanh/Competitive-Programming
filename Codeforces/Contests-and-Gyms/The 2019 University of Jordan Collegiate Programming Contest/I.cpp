// Author: Hai Minh Phan
#include <bits/stdc++.h>
using namespace std;

bool isNum(char c){
	return(int(c) > 47 && int(c) < 58);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> cur(n);
	vector<int> ans(n + 1);

	int level = 0;
	string temp;
	for(char c : s){
		if(isNum(c)){
			temp += c;
			continue;
		}
		if(c == '('){
			if(temp != "") cur[level] = stoi(temp);
			temp = "";
			++level;
		}
		if(c == ')'){
			int val;
			if(temp != "") val = stoi(temp);
			else val = cur[level];
			temp = "";

			--level;
			ans[val] = cur[level];
		}
	}

	for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}