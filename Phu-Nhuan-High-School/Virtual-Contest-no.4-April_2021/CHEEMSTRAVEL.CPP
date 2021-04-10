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
		freopen((name+".INP").c_str(), "r", stdin); // see /general/io
		freopen((name+".OUT").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e2+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
int dist[MX][MX], N, mindist = MOD, curdist;
vector<pair<int,int>> adj[MX];
bool visited[MX];

/*
void dfs(int node, int curdist, int cnt) {
	//visited[node] = true;
	if (cnt == N) {
		ckmin(mindist,curdist); return;
	}
	int minD = MOD;
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			ckmin(minD,dist[node][i]);
		}
	}
	if (minD == MOD) return;
	for (int i = 1; i <= N; ++i) {
		if (dist[node][i] == minD && !visited[i]) {
			visited[i] = true;
			dfs(i,curdist+dist[node][i],cnt+1);
			visited[i] = false;
		}
	}
}
*/

void dfs(int node) {
	visited[node] = true;
	for (pi& p : adj[node]) {
		if (!visited[p.f]) {
			curdist += p.s;
			dfs(p.f);
		}
	}
	return;
}

int main() {
	setIO("CHEEMSTRAVEL");
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	for (int i = 0; i < MX; ++i) fill(all(dist[i]),MOD);
	for (int i = 0; i < MX; ++i) dist[i][i] = 0;
	for (int i = 0; i < N; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].pb(mp(B,0));
		adj[B].pb(mp(A,C));
		dist[A][B] = 0;
		dist[B][A] = C;
	}
	/*
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				ckmin(dist[i][j],dist[i][k]+dist[k][j]);
	*/
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 2; ++j) {
			memset(visited,false,sizeof(visited));
			curdist = dist[i][adj[i][j].f] + dist[adj[i][1-j].f][i];
			visited[i] = true;
			dfs(adj[i][j].f);
			//debug(i);
			//debug(adj[i][j].f);
			//debug(adj[i][1-j].f);
			//debug(curdist);
			cout << endl;
			ckmin(mindist,curdist);
		}
	}
	cout << mindist;
	return 0;
}
