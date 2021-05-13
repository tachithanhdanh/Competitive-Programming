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
#define db(x) cerr << (#x) << " is " << (x) << endl
#else
#define db(x)
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
const int MX = 1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};

//variables used for the current problem
const int d = 300;
bool a[700][700], danger;
char dir;
int times, D, x = -1+d, y = -5+d;

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	for (int i = -1; i >= -3; --i) a[d][i+d] = true;
	for (int i = 0; i < 8; ++i) if (i != 4) a[i+d][-3+d] = true;
	for (int i = 3; i < 9; i += 2) a[i+d][-4+d] = true;
	for (int i = 3; i < 6; ++i) a[i+d][-5+d] = true;
	for (int i = -3; i >= -7; --i) a[7+d][i+d] = true;
	for (int i = -5; i >= -7; --i) a[-1+d][i+d] = true;
	for (int i = -1; i < 8; ++i) a[i+d][-7+d] = true;
	//for (int i = 310; i >= 290; --i)
	//	for (int j = 310; j >= 290; --j)
	//		cout << a[j][i] << " \n"[j==290];
	while (cin >> dir >> times) {
		if (dir == 'q') break;
		for (int i = 0; i < 4; ++i)
			if (dc[i] == dir) D = i;
		for (int t = 1; t <= times; ++t) {
			if (a[t*dx[D]+x][t*dy[D]+y]) {
				//cout << t*dx[D]+x-d << " " << t*dy[D]+y-d << endl;
				danger = true;
			}
			else a[t*dx[D]+x][t*dy[D]+y] = true;
		}
		x += times*dx[D], y += times*dy[D];
		cout << x-d << ' ' << y-d << ' ';
		if (danger) {
			cout << "DANGER\n";
			break;
		}
		else cout << "safe\n";
	}
	return 0;
}
