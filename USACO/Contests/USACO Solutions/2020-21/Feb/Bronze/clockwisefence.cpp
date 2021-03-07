#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem


int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int deg = 0;
		s += s[0];
		for (int i = 1; i < sz(s); ++i) {
			if (s[i] != s[i-1]) {
				if ((s[i-1] == 'E' && s[i] == 'S') || (s[i-1] == 'S' && s[i] == 'W') || (s[i-1] == 'W' && s[i] == 'N') || (s[i-1] == 'N' && s[i] == 'E')) deg +=90;
				else deg -= 90;
			}
		}
		//cout << deg << endl;
		//deg += 90;
		cout << (deg == 360 ? "" : "C") << "CW" << endl;
	}
	return 0;
}
