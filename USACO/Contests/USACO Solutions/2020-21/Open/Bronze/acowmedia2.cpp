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
const int MX = 2e4+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

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
// Time complexity: O(N*K*(N+K))
int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int K, N;
	cin >> K >> N;
	vs mem(N);
	vector<vs> contri(K,vs(N));
	vector<vi> ranking(K,vi(N)), pos(N,vi(K));
	for (str& S : mem) cin >> S;
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> contri[i][j];
		}
	}
	auto find = [&](const int& i, const int& j){
		for (int k = 0; k < N; ++k)
			if (mem[j] == contri[i][k])
				return ranking[i][k];
	};
	for (int i = 0; i < K; ++i) {
		int top = 1;
		ranking[i][0] = top;
		for (int j = 1; j < N; ++j) {
			if (contri[i][j-1] < contri[i][j]) ranking[i][j] = top;
			else ranking[i][j] = ++top;
		}
		//for (int j = 0; j < N; ++j)
		//	for (int k = 0; k < N; ++k)
		//		if (mem[j] == contri[i][k])
		//			pos[j][i] = ranking[i][k];
		for (int j = 0; j < N; ++j)
			pos[j][i] = find(i,j);
		//for (int j = 0; j < N; ++j)
		//	cout << pos[j][i] << " ";
		//cout << endl;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) cout << 'B';
			else {
				bool more_senior = false, all_equal = true;
				for (int k = 0; k < K; ++k) {
					more_senior |= pos[i][k] > pos[j][k];
					all_equal &= pos[i][k] == pos[j][k];
				}
				if (all_equal) cout << '?';
				else cout << more_senior;
			}
		}
		cout << endl;
	}
 	return 0;
}
