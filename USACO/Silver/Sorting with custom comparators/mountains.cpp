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
struct Mountain {
	int x, y, left_interval, right_interval;
	void update() { left_interval = x - y, right_interval = x + y; }
	// the base of the right triangle is in the interval [x-y,x+y]
	// Proof : tam giác vuông cân nên đường cao là đường trung tuyến và trung tuyến ứng với cạnh huyền bằng nửa cạnh huyền.
	// Đề cho tam giác vuông cân với đỉnh có tọa độ (x,y) và cạnh huyền nằm trên trục x
	// Vì thế, đường cao = đường trung tuyến = y và cạnh huyền = 2*y với TĐ nằm ở vị trí x trên trục Ox
	// cho nên cạnh nó sẽ kéo dài từ x-y đến x+y trên trục Ox.
	bool operator<(const Mountain& mount) {
		if (left_interval == mount.left_interval) return right_interval > mount.right_interval;
		return left_interval < mount.left_interval;
	}
};


int main() {
	setIO("mountains");
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int N;
	cin >> N;
	vector<Mountain> M(N);
	for (auto& mount : M) {
		cin >> mount.x >> mount.y; mount.update();
	}
	sort(all(M));
	int max_right_interval = -1, counts = 0;
	for (auto& mount : M) {
		if (mount.right_interval > max_right_interval) {
			//cout << mount.x << " " << mount.y << endl;
			++counts;
			max_right_interval = mount.right_interval;
		}
	}
	cout << counts;
	return 0;
}
