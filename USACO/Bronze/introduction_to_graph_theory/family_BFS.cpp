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
const int MX = 2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

//variables used for the current problem
vector<pair<string,int>> dist[3];

struct Edge {
	string u, v;
};

int main() {
	setIO("family");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int N;
	string c[3];
	cin >> N >> c[1] >> c[2];
	dist[1].pb(mp(c[1],0));
	dist[2].pb(mp(c[2],0));
	vector<Edge> E(N);
	for (int i = 0; i < N; ++i) {
		string u, v;
		cin >> v >> u;
		E[i] = {u,v};
		bool f1 = true, f2 = true;
	}
	for (int k = 1; k <= 2; ++k) {
		queue<string> q;
		q.push(c[k]);
		// BFS on directed tree
		while (!q.empty()) {
			string node = q.front();
			q.pop();
			for (Edge& edge : E)
				if (edge.u == node)	{
					q.push(edge.v);
					for (int j = 0; j < sz(dist[k]); ++j)
						if (dist[k][j].f == node) {
							dist[k].pb(mp(edge.v,dist[k][j].s+1)); break;
						}
					break;
				}
		}
	}
	string ancestor = no;
	int d1 = MX, d2 = MX;
	for (int i = 0; i < sz(dist[1]); ++i) for (int j = 0; j < sz(dist[2]); ++j)
		if (dist[1][i].f == dist[2][j].f && (d1 > dist[1][i].s || d2 > dist[2][j].s)) {
			ancestor = dist[1][i].f;
			d1 = dist[1][i].s;
			d2 = dist[2][j].s;
		}
	if (ancestor == no) cout << "NOT RELATED";
	else if (ancestor == c[2] || ancestor == c[1]) {
		if (ancestor == c[1]) swap(c[1],c[2]), swap(d1,d2);
		cout << c[2] << " is the ";
		if (d1 >= 2) {
			for (int i = 0; i < d1 - 2; ++i) cout << "great-";
			cout << "grand-";
		}
		cout << "mother of " << c[1];
	}
	else {
		if (d2 < d1) swap(d2,d1), swap(c[2],c[1]);
		if (d1 == 1 && d2 == 1) cout << "SIBLINGS";
		else if (d1 == 1) {
			cout << c[1] << " is the ";
			for (int i = 0; i < d2 - 2; ++i) cout << "great-";
			cout << "aunt of " << c[2];
		}
		else cout << "COUSINS";
	}
	return 0;
}
