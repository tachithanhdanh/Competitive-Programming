/**
*    author:    tachithanhdanh
*    created:    2022-09-03    15:17:09
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#define endl "\n"

using ll = long long;
using str = string;

// vectors
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vs = vector<str>;
#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back

// pairs
using pi = pair<int, int>;
using vpi = vector<pi>;
#define f first
#define s second
#define mp make_pair

// set min-max value.
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<typename T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; } // set a = max(a,b)

// constant initialization
const str yes="YES\n", no="NO\n";
const int MOD = 1e9 + 7; // 998244353
const int MX = 2e5 + 10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
const char dc[4] = {'r', 'u', 'l', 'd'};
const bool multitest = true;

struct Rect {
	int x1{}, x2{}, y1{}, y2{};
	Rect(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;
	}
};

void solve() {
	int W, H, w, h;
	cin >> W >> H;
	int x[2], y[2];
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	Rect a = Rect(x[0], y[0], x[1], y[1]);
	cin >> w >> h;
	x[0] = 0;
	x[1] = W - w;
	y[0] = 0;
	y[1] = H - h;
	int ans{MOD};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			Rect b = Rect(x[i], y[j], x[i] + w, y[j] + h);
			int iW = min(a.x2, b.x2) - max(a.x1, b.x1);
			int iH = min(a.y2, b.y2) - max(a.y1, b.y1);
			if (iW < 0 || iH < 0) return void(cout << 0 << endl);
			if (iW > 0) {
				if (b.x1 == 0) iW = (a.x2 + (b.x2 - a.x1) <= W? (b.x2 - a.x1) : MOD);
				else iW = (a.x1 - (a.x2 - b.x1) >= 0? (a.x2 - b.x1) : MOD);
			}
			if (iH > 0) {
				if (b.y1 == 0) iH = (a.y2 + (b.y2 - a.y1) <= H? (b.y2 - a.y1) : MOD);
				else iH = (a.y1 - (a.y2 - b.y1) >= 0? (a.y2 - b.y1) : MOD);
			}
			ckmin(ans,min(iW, iH));
		}
	}
	cout << (ans == MOD? -1 : ans) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		// cout << "test " << t+1 << endl;
		solve();
	}
	return 0;
}