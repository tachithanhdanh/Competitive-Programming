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
const int MX = 1e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
 
//variables used for the current problem
int N, M, rooms;
char grid[MX][MX];
bool visited[MX][MX];
 
bool isvalid(const int& i, const int& j) {
	return i >= 0 && i < N && j >= 0 && j < M && grid[i][j] == '.' && !visited[i][j];
}
 
void ff(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 4; ++k) {
		if (isvalid(i+dx[k],j+dy[k])) ff(i+dx[k],j+dy[k]);
	}
	return;
}
 
int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> grid[i][j];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!visited[i][j] && grid[i][j] == '.') {
				++rooms;
				ff(i,j);
			}
		}
	}
	cout << rooms;
	return 0;
}