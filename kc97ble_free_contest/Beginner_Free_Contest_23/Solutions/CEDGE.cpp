#include <bits/stdc++.h>
 
using namespace std;
const string filename = "CEDGE";
 
typedef pair<int, int> ii;
 
int n;
int res[100001], col[100001];

int cnt = 0;
vector<ii> AdjList[100001];
 
void dfs(int u, int p, int pre_col)
{
	int cur_col = 0;
	for (int i = 0; i < AdjList[u].size(); i++)
	{
		int v = AdjList[u][i].first;
		int id = AdjList[u][i].second;
		if (v != p)
		{
			cur_col++;
			if (cur_col == pre_col) cur_col++;
			dfs(v, u, cur_col);
			col[id] = cur_col;
		}
	}
	cnt = max(cnt, cur_col);
}
 
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    freopen( (filename + ".inp").c_str(), "r", stdin);
    freopen( (filename + ".out").c_str(), "w", stdout);
       
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u,v;
		cin >> u >> v;
		AdjList[u].push_back(ii(v, i));
		AdjList[v].push_back(ii(u, i));
	}
	dfs(1, -1, -1);          
	cout << cnt << '\n';
	for (int i = 1; i <= n - 1; i++)
		cout << col[i] << '\n';
}