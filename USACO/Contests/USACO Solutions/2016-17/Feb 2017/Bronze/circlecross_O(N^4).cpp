#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
	string s; cin >> s;
	int ans = 0;
	for (int a = 0; a < s.size(); ++a) 
		for (int b = a+1; b < s.size(); ++b) 
			for (int c = b+1; c < s.size(); ++c) 
				for (int d = c+1; d < s.size(); ++d) 
					ans += s[a] == s[c] && s[b] == s[d];
	cout << ans;
}