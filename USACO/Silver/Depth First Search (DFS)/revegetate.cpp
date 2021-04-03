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
#define debug(x) cout << (#x) << " is " << (x) << endl
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
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, M, colors[MX], components;
vi S[MX], D[MX];
bool impossible;

void dfs(int& node, int color) {
	colors[node] = color;
	for (int& u : S[node]) {
		if (!colors[u]) dfs(u,color);
		if (colors[u] != colors[node]) impossible = true;
	}
	for (int& u : D[node]) {
		if (!colors[u]) dfs(u,3-color);
		if (colors[u] == colors[node]) impossible = true;
	}
	return;
}

int main() {
	setIO("revegetate");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		char c;
		cin >> c >> u >> v;
		if (c == 'S') {
			S[u].pb(v);
			S[v].pb(u);
		}
		else {
			D[v].pb(u);
			D[u].pb(v);
		}
	}
	for (int node = 1; node <= N; ++node) {
		if (!colors[node])	{
			++components;
			dfs(node,1);
		}
	}
	if (impossible) return cout << 0, 0;
	cout << 1;
	for (int i = 0; i < components; ++i) cout << 0;
	return 0;
}
