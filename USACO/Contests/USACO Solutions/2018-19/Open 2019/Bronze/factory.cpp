#include <bits/stdc++.h>
using namespace std;

//vector
#define vt vector
#define pb push_back

//variables used for the current problem
int n,a,b,cnt[101]; vt<int> adj[101];
bool visited[101];

void dfs(int node){
	visited[node]=true; ++cnt[node];
	for (int u : adj[node]){
		if (!visited[u]){
			dfs(u);
		}
	}
	return;
}

void solve(){ 
	cin >> n;
	for (int i=1;i<n;++i){
		cin >> a >> b;
		adj[a].pb(b);
	}
	for (int i=1;i<=n;++i){
		memset(visited,false,sizeof(visited));
		dfs(i);
	}
	for (int i=1;i<=n;++i){
		if (cnt[i]==n){
			cout << i <<'\n'; return;
		}
	}
	cout << -1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("factory.in", "r", stdin); 
	freopen("factory.out", "w", stdout);
	return 0;
}
