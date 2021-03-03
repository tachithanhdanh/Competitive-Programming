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
int component1, strongly_connected_component;

void dfs(int node) {
	visited[node] = true;
	++visits;
	for (int &u : adj[node]) {
		if (!visited[u]) {
			dfs(u);
		}
	}
}

int main() {
	setIO("NYTRAVEL");
	//setIO();
	//Bài toán yêu cầu ta tìm 2 thành phần liên thông mạnh
	//Với thành phần đầu tiên BẮT BUỘC PHẢI CHỨA ĐỈNH 1 (VÌ BẮT ĐẦU ĐI THĂM TẠI ĐỈNH 1)
	//Thành phần thứ hai không liên quan đến thằng đầu (nghĩa là không chung đỉnh lẫn cạnh)
	//Ta ghép 2 thành phần liên thông đó tạo thành 1 thành phần liên thông mạnh chứa nhiều đỉnh nhất 
	//Đáp án : số đỉnh của TP1 + TP2

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	component1 = visits;
	for (int i = 2; i <= N; ++i) {
		//fill(visited,visited + N + 5, false);
		if (visited[i]) continue;
		visits = 0;
		dfs(i);
		strongly_connected_component = max(strongly_connected_component, visits);
	}
	cout << component1 + strongly_connected_component;
	return 0;
}
