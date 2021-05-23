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

//for printing variables when debugging
#ifdef LOCAL
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//Set min-max value.
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

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
const int MX = 1e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

//variables used for the current problem
int N, maxscore = -MOD, ans, when = MX;
vector<string> name;
vector<pi> Log[1050];
vi overall;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string S;
		int score, pos = -1;
		cin >> S >> score;
		for (int j = 0; j < sz(name); ++j) {
			if (name[j] == S) {
				pos = j;
				break;
			}
		}
		if (pos == -1) {
			pos = sz(name);
			name.pb(S);
		}
		Log[pos].pb(mp(score,i));
	}
	for (int i = 0; i < sz(name); ++i) {
		int cur = 0;
		for (pi& p : Log[i]) {
			cur += p.f;
		}
		overall.pb(cur);
	}
	for (int& score : overall) {
		ckmax(maxscore,score);
	}
	for (int i = 0; i < sz(overall); ++i) {
		if (maxscore == overall[i]) {
			int cur = 0;
			for (pi& l : Log[i]) {
				cur += l.f;
				if (cur >= maxscore && l.s < when) {
					when = l.s;
					ans = i;
					break;
				}
			}
		}
	}
	cout << name[ans];
	return 0;
}
