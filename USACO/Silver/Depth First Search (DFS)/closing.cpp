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
const int MX = 3e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N, M;
vi adj[MX], nodes;
bool visited[MX];
int visits;

void dfs(int node) {
	visited[node] = true;
	++visits;
	for (int& u : adj[node]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
	return;
}

int main() {
	setIO("closing");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	cin >> N >> M;
	nodes.resize(N-1);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < N - 1; ++i) {
		cin >> nodes[i];
		fill(visited,visited + N + 5, false);
		for (int j = 0; j < i; ++j) visited[nodes[j]] = true;
		visits = 0;
		dfs(nodes[i]);
		cout << (visits == N-i ? yes : no);
	}
	cout << yes;
	return 0;
}
