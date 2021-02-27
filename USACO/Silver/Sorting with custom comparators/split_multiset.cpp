#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

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

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

//constant initialization
const string yes="YES",no="NO";
const int MOD=1e9+7; //998244353
const int maxn=2e6+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
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

ll area_before, area_after = INF + INF, curArea, areaL, areaR;
int minX, maxX, minY, maxY;

int main() { //clearer implementation here: https://usaco.guide/solutions/usaco-645/#implementation
	setIO("split");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif //LOCAL
	int N;
	cin >> N;
	vector<Cow> cows(N);
	multiset<int> allX, allY;
	for (Cow& cow : cows) {
		cin >> cow.x >> cow.y;
		allX.insert(cow.x);
		allY.insert(cow.y);
	}
	minX = *allX.begin();
	maxX = *allX.rbegin();
	minY = *allY.begin();
	maxY = *allY.rbegin();
	area_before = 1LL * (maxX - minX) * (maxY - minY);
	sort(all(cows),cmp1);
	for (int k = 0; k <= 1; ++k) {
		multiset<int> leftX, leftY, rightX, rightY;
		rightX = allX;
		rightY = allY;
		for (int i = 0; i < N; ++i) {
			leftX.insert(cows[i].x);
			leftY.insert(cows[i].y);
			rightX.erase(rightX.find(cows[i].x));
			rightY.erase(rightY.find(cows[i].y));
			minX = *leftX.begin();
			maxX = *leftX.rbegin();
			minY = *leftY.begin();
			maxY = *leftY.rbegin();
			areaL = 1LL * (maxX - minX) * (maxY - minY);
			if (sz(rightX)) {
				minX = *rightX.begin();
				maxX = *rightX.rbegin();
				minY = *rightY.begin();
				maxY = *rightY.rbegin();
				areaR = 1LL * (maxX - minX) * (maxY - minY);
			}
			curArea = areaL + areaR;
			area_after = min(area_after, curArea);
		}
		sort(all(cows),cmp2);
	}
	cout << area_before - area_after;
	return 0;
}
