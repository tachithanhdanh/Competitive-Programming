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
const int MX = 1e4+10;
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

int N, S, W, H, type, Ci;
char C[6][16][16][16], ans[101][101][16][16], result[16][16], pre[16][16];
str query;
pi q[101][101];

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < S; ++j) {
			for (int k = 0; k < S; ++k) {
				cin >> C[0][i][j][k];
			}
		}
	}
	cin >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> query;
			q[i][j] = mp(query[0]-'0',query[2]-'0');
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < S; ++k) {
				for (int p = 0; p < S; ++p) {
					pre[k][p] = result[k][p];
				}
			}
			if (j && j < 4) {
				for (int k = 0; k < S; ++k) {
					for (int p = 0; p < S; ++p) {
						result[p][S-k-1] = pre[k][p];
					}
				}
			}
			else if (j == 4) {
				for (int k = 0; k < S; ++k) {
					for (int p = 0; p < S; ++p) {
						result[k][S-p-1] = C[0][i][k][p];
					}
				}
			}
			else if (j == 5) {
				for (int k = 0; k < S; ++k) {
					for (int p = 0; p < S; ++p) {
						result[S-k-1][p] = C[0][i][k][p];
					}
				}
			}
			if (j) {
				for (int k = 0; k < S; ++k) {
					for (int p = 0; p < S; ++p) {
						C[j][i][k][p] = result[k][p];
					}
				}
			}
			else {
				for (int k = 0; k < S; ++k) {
					for (int p = 0; p < S; ++p) {
						result[k][p] = C[j][i][k][p];
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < S; ++j) {
			for (int k = 0; k < S; ++k) {
				cout << C[i][0][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
	*/
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			Ci = q[i][j].f;
			type = q[i][j].s;
			for (int k = i*S; k < (i+1)*S; ++k) {
				for (int p = j*S; p < (j+1)*S; ++p)	{
					ans[i][j][k-i*S][p-j*S] = C[type][Ci][k-i*S][p-j*S];
				}
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		for	(int j = 0; j < S; ++j) {
			for (int k = 0; k < W; ++k) {
				for (int p = 0; p < S; ++p) {
					cout << ans[i][k][j][p];
				}
			}
			cout << endl;
		}
	}
 	return 0;
}
