#include <bits/stdc++.h>
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

void setIO (string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return b > a ? a = b, 1 : 0; }

struct Cow {
	int x, y;
};

bool cmp1 (const Cow& c1, const Cow& c2) {
	if (c1.x == c2.x) return c1.y < c2.y;
	return c1.x < c2.x;
}

bool cmp2 (const Cow& c1, const Cow& c2) {
	if (c1.y == c2.y) return c1.x < c2.x;
	return c1.y < c2.y;
}

struct Info {
	int maxX1, maxY1, minX1 = MOD, minY1 = MOD;
	int maxX2, maxY2, minX2 = MOD, minY2 = MOD;
};

int maxX, maxY, minX = MOD, minY = MOD;
ll area_before, area_after = 4*INF;

signed main() {
	setIO("split");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N;
	cin >> N;
	vector<Cow> cows(N);
	for (Cow& cow : cows) {
		cin >> cow.x >> cow.y;
		ckmax(maxX,cow.x);
		ckmin(minX,cow.x);
		ckmax(maxY,cow.y);
		ckmin(minY,cow.y);
	}
	area_before = 1LL*(maxX-minX)*(maxY-minY);
	sort(all(cows),cmp1);
	for (int k = 0; k <= 1; ++k){
		vector<Info> info(N+1);
		for (int i = 0; i < N; ++i) {
			ckmax(info[i+1].maxX1,max(cows[i].x,info[i].maxX1));
			ckmin(info[i+1].minX1,min(cows[i].x,info[i].minX1));
			ckmax(info[i+1].maxY1,max(cows[i].y,info[i].maxY1));
			ckmin(info[i+1].minY1,min(cows[i].y,info[i].minY1));
		}
		for (int i = N - 1; i >= 0; --i) {
			ckmax(info[i].maxX2,max(cows[i].x,info[i+1].maxX2));
			ckmin(info[i].minX2,min(cows[i].x,info[i+1].minX2));
			ckmax(info[i].maxY2,max(cows[i].y,info[i+1].maxY2));
			ckmin(info[i].minY2,min(cows[i].y,info[i+1].minY2));
		}
		info[0].maxX1 = info[0].minX1 = info[0].maxY1 = info[0].minY1 = 0;
		info[N].maxX2 = info[N].minX2 = info[N].maxY2 = info[N].minY2 = 0;
		for (int i = 0; i <= N; ++i) {
			ll first_enclosure = 1LL*(info[i].maxX1-info[i].minX1)*(info[i].maxY1-info[i].minY1);
			ll second_enclosure = 1LL*(info[i].maxX2-info[i].minX2)*(info[i].maxY2-info[i].minY2);
			ll curArea = first_enclosure + second_enclosure;
			ckmin(area_after,curArea);
		}
		sort(all(cows),cmp2);
	}
	cout << area_before - area_after;
	return 0;
}
