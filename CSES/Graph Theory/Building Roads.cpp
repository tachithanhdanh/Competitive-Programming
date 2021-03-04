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
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N, M;
vi adj[MX], nodes;
bool visited[MX];

void dfs(int node) {
	visited[node] = true;
	for (int& u : adj[node]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
	return;
}

int main() {
	setIO();
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int node = 1; node <= N; ++node) {
		if (visited[node]) continue;
		dfs(node);
		nodes.pb(node);
	}
	cout << sz(nodes) - 1 << endl;
	if (sz(nodes) > 1) {
		for (int i = 1; i < sz(nodes); ++i){
			cout << nodes.front() << " " << nodes[i] << endl;
		}
	}
	return 0;
}
