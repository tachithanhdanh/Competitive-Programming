#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="Yes",no="No";
const int MOD=1e9+7; //998244353
const int maxn=1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N, M, L, F, f;
vi adj[10001]; bool visited[10001];
int ans;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    cin >> N >> M >> L;
    F0R(i,L+1) {
        if (i-M>=0) adj[i].pb(i-M);
        if (i+N>=0) adj[i].pb(i+N);
    }
    dfs(0);
    cin >> F;
    while (F--) {
        cin >> f; ans += visited[f];
    }
    cout << ans;
    return 0;
}
