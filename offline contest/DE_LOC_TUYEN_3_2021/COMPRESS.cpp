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

#define debug(x) cout << #x << " = " << (x) << endl;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (sz(name)) {
		freopen((name+".INP").c_str(),"r",stdin);
		freopen((name+".OUT").c_str(),"w",stdout);
	}
	#ifdef DANHDEBUG
	freopen("input.txt","r",stdin);
	#endif // DANHDEBUG
}

//constant initialization
const int MX = 1E5 + 10;
const int MOD = 1E9 + 7; // INF for int_32t
const ll INF = 1e18; // Not too close to LLONG_MAX

//variables for current problem
string s, ans;

int main() {
	setIO("COMPRESS");
	//brute force O(N^2) (hope it may pass all test cases)
	//hmm
	//find all substring with length X such that sz(S) is divisible by X.
	cin >> s;
	if (!sz(s)) {
		cout << 0; return 0;
	}
	for (int i = 1; i <= sz(s); ++i) {
		if (sz(s) % i == 0) {
			ans = "";
			int k = sz(s) / i;
			string temp = s.substr(0,i);
			for (int j = 0; j < k; ++j) {
				ans += temp;
			}
			//debug(ans);
			//debug(k);
			if (ans == s) {
				cout << k << temp; return 0;
			}
		}
	}
	return 0;
}

