#include bitsstdc++.h  see generalrunning-code-locally
using namespace std;

#define endl n

using ll = long long;

vectors
using vi = vectorint;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

pairs
using pi = pairint,int;
#define f first
#define s second
#define mp make_pair

for printing variables when debugging
#ifdef LOCAL
#define debug(x) cerr  (#x)   is   (x)  endl
#else
#define debug(x)
#endif  LOCAL

Set min-max value.
templateclass T bool ckmin(T& a, const T& b) { return b  a  a = b, 1  0; }  set a = min(a,b)
templateclass T bool ckmax(T& a, const T& b) { return b  a  a = b, 1  0; }  set a = max(a,b)

void setIO(string name = ) {
	cin.tie(0)-sync_with_stdio(0);  see generalfast-io
	if (sz(name)) {
		freopen((name+.in).c_str(), r, stdin);  see generalio
		freopen((name+.out).c_str(), w, stdout);
	}
}

constant initialization
const string yes=YESn,no=NOn;
const int MOD = 1e9+7; 998244353
const int MX = 3e3+10;
const ll INF = 1e18; Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};  for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

variables used for the current problem
int N, M, dist[MX], ans = MOD;
vi adj[MX];

int main() {
	setIO();
	#ifdef LOCAL
	freopen(input.txt, r, stdin);
	#endif  LOCAL
	cin  N  M;
	for (int i = 0; i  M; ++i) {
		int u, v;
		cin  u  v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i = N; ++i) {
		 BFS for every vertex
		fill(dist,dist+N+1,MOD);
		queueint q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int next  adj[node]) {
				if (dist[next] == MOD) {
					dist[next] = dist[node] + 1;
					q.push(next);
					for (int u  adj[next]) {
						if (u != node) ckmin(ans,dist[next]+dist[u]+1);
					}
				}
			}
		}
	}
	cout  (ans == MOD -1  ans);
	return 0;
}
