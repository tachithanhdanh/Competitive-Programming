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
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int N, M, trace[MX], dist[MX];
vi adj[MX], route;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// BFS
	fill(all(dist),MOD);
	dist[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int next : adj[node]) {
			if (dist[next] == MOD) { // Not visited yet
				trace[next] = node;
				dist[next] = dist[node] + 1;
				q.push(next);
			}
		}
	}
	if (dist[N] == MOD) return cout << "IMPOSSIBLE", 0;
	cout << dist[N] << endl;
	int node = N;
	route.pb(N);
	do {
		route.pb(trace[node]);
		node = trace[node];
	} while (node != 1);
	for (int i = sz(route)-1; i >= 0; --i) cout << route[i] << " ";
	return 0;
}
