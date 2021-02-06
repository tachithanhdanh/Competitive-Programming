#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
	string s; cin >> s;
	int Start[26], Exit[26];
	//Set all elements of Start and End arrays to -1.
	fill(Start, Start + 26, -1);
	fill(End, End + 26, -1);
	for (int i = 0; i < s.size(); ++i) {
		if (Start[s[i]-'A'] == -1) Start[s[i]-'A'] = i;
		else End[s[i]-'A'] = i;
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			ans += Start[i] < Start[j] && Start[j] < End[i] && End[i] < End[j];
	cout << ans;
}