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
#define debug(x) cerr << (#x) << " is " << (x) << endl
#else
#define debug(x)
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
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, M, tags[MX], minans, maxans;
vector<pair<string,int>> items;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> tags[i];
	for (int i = 0; i < M; ++i) {
		string item;
		cin >> item;
		bool flag = true;
		for (auto& p : items) {
			if (p.f == item) {
				++p.s, flag = false;
				break;
			}
		}
		if (flag) items.pb(mp(item,1));
	}
	sort(all(items),[](const pair<string,int>& i1, const pair<string,int>& i2){
		if (i1.s == i2.s) return i1.f < i2.f;
		return i1.s < i2.s;
	});
	sort(tags,tags+N);
	for (int i = 0; i < sz(items); ++i) {
		minans += items[sz(items)-i-1].s*tags[i];
		maxans += items[i].s*tags[N-sz(items)+i];
	}
	cout << minans << " " << maxans;
	return 0;
}
