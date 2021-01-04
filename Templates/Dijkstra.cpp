#include <bits/stdc++.h>
using namespace std;

//constant initialization
const int maxn=1e5+10; //maximum number of vertices
const long long INF=1e18; //not too close to LLONG_MAX

///variables used for the current problem
int N,M,a,b,c;
long long dist[maxn]; //shortest distance array
vector<pair<int,int>> adj[maxn]; //adjacency list
bool processed[maxn]; //an array storing the state of the vertices

void dijkstra(int source){
	for (int i=0;i<=N;++i){
		dist[i]=INF;
	}
	dist[source]=0;
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.push(make_pair(0,source));
	while (!pq.empty()){
		long long current_dist; int node;
		tie(current_dist,node)= pq.top(); pq.pop();
		if (processed[node]) continue; //It's important to include continue to avoid TLE
		processed[node]=true;
		for (pair<long long,int> edge : adj[node]){
			if (dist[node] + edge.second < dist[edge.first]){
				dist[edge.first] = dist[node] + edge.second;
				pq.push(make_pair(dist[edge.first],edge.first));
			}
		}
	}
}

//Verification: https://cses.fi/problemset/task/1671
void solve(){
    cin >> N >> M;
    for (int i=0;i<M;++i){
    	cin >> a >> b >> c;
    	adj[a].push_back(make_pair(b,c)); //The graph is directed
    	//If it is undirected then include the below line.
    	//adj[b].push_back(make_pair(a,c));
    }
    dijkstra(1);
    for (int i=1;i<=N;++i){
    	cout << dist[i] << " ";
    }
    return;
}

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	solve();
	return 0;
}
