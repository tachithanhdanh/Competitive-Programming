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
vi adj[MX];
int N, M;
bool visited[MX];
int visits, ans;
int mxV1, mxV2;
int u1, u2;

void dfs(int node) {
	visited[node] = true;
	++visits;
	for (int &u : adj[node]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
}

void sub1() {
	for (int i = 1; i <= N; ++i) for (int j = i + 1; j <= N; ++j) {
		adj[i].pb(j);
		fill(visited,visited + N + 5, false);
		visits = 0;
		dfs(i);
		adj[i].pop_back();
		ans = max(ans, visits);

		adj[j].pb(i);
		fill(visited,visited + N + 5, false);
		visits = 0;
		dfs(j);
		adj[j].pop_back();
		ans = max(ans, visits);
	}
}

void sub2() {
	for (int i = 1; i <= N; ++i) {
		//fill(visited,visited + N + 5, false);
		if (visited[i]) continue;
		visits = 0;
		dfs(i);
		ans = max(ans, visits);

		if (visits > mxV1) {
			mxV2 = mxV1;
			u2 = u1;
			u1 = i;
			mxV1 = visits;
		}
		else if (visits > mxV2) {
			u2 = i;
			mxV2 = visits;
		}
	}
	if (u1 != u2 && u2 && u1) {
		adj[u1].pb(u2);
	}
	fill(visited,visited + N + 5, false);
	visits = 0;
	//debug(u1);
	dfs(u1);
	ans = max(ans, visits);
}

int main() {
	setIO("NYTRAVEL");
	//setIO();
	//fuck, finding largest cycle?????
	//I am suck at Graph Theory so I'm just gonna grab some partial points (again)
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (N <= 500) sub1();
	else sub2();
	cout << ans;
	return 0;
}

