// Author: Danh Ta Chi Thanh
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
using str = string;

//vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define pb push_back

//pairs
using pi = pair<int,int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

//for printing variables when debugging
#ifdef LOCAL
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
#endif // LOCAL

//constant initialization
const str yes="YES\n",no="NO\n";
const int MOD = 1e9+7; //998244353
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

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

//int dist[15][15];
//vpi pos = {{3,3}, {3,10}, {10,3}, {10,10}};
//pi pos = mp(3,3);
bool b[15][15], v[15][15];
char trace[15][15];

bool valid(int X, int Y) {
	return X >= 1 && Y >= 1 && X <= 12 && Y <= 12 && !v[X][Y] && !b[X][Y];
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int X = x + dx[i], Y = y + dy[i];
		if (valid(X,Y)) {
			v[X][Y] = true;
			trace[X][Y] = dc[i];
			//cout << X << "  " << Y << " " << dc[i] << endl;
			dfs(X,Y);
		}
	}
}

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	b[6][6] = b[6][7] = b[7][6] = b[7][7] = b[9][2] = b[10][2] = b[9][3] = b[9][10] = b[9][11] = b[10][11] = true;
	int L;
	cin >> L;
	while (L--) {
		// BFS
		int x, y;
		cin >> x >> y;
		for (int i = 0; i < 15; ++i) {
			fill(all(v[i]),false);
			fill(all(trace[i]),'\0');
		}
		dfs(x,y);
		int X = 3, Y = 3;
		vector<char> ans;
		//cout << trace[X][Y];
		//cout << trace[X+1][Y];
		while (true) {
			ans.pb(trace[X][Y]);
			int p;
			for (int i = 0; i < 4; ++i) if (trace[X][Y] == dc[i]) {
				p = i; break;
			}
			X -= dx[p], Y -= dy[p];
			//cout << X << " " << Y << endl;
			if (X == x && Y == y) break;
		}
		reverse(all(ans));
		cout << sz(ans) << endl;
		for(auto& c : ans) cout << c;
		cout << endl;
	}
 	return 0;
}
