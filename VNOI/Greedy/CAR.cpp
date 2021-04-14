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
const int MX = 3e3+10;
const ll INF = 1e18; //Not too close to LLONG_MAX
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
const char dc[4] = {'D', 'R', 'U', 'L'};

//variables used for the current problem
int N;
ll ans; // Số to nên dùng long long

struct C { // struct xe_hơi
	// a là tiên phạt của xe đó (đơn vị đồng/ ngày)
	// b là số ngày cần để sửa xong xe đó
	// index là biến lưu vị trí ban đầu của xe đó (trước khi sort)
	int a, b, index;
};

int main() {
	setIO();
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	cin >> N;
	vector<C> cars(N);
	for (int i = 0; i < N; ++i) cin >> cars[i].a;
	for (int i = 0; i < N; ++i) cin >> cars[i].b;
	for (int i = 0; i < N; ++i) cars[i].index = i+1;
	sort(all(cars),[](const C& c1, const C& c2){ // Phần sort này có gì tự chứng minh toán :v
		// Nếu tiền phạt của 2 xe bằng nhau thì xe nào sửa xong nhanh hơn thì cho sử trước
		if (c1.a == c2.a) return c1.b < c2.b;

		// Nếu thời gian sửa 2 xe bằng nhau thì xe nào bị phạt tốn nhiều tiền hơn sửa trước
		if (c1.b == c2.b) return c1.a > c2.a;

		// TH tổng quát thì c1 < c2 khi và chỉ khi
		//số tiền c1 trước, c2 sửa sau bé hơn số tiền c2 sửa trước, c1 sửa sau.
		return c1.a*c1.b + c2.a*(c1.b+c2.b) < c1.a*(c1.b+c2.b) + c2.a*c2.b;
	});
	for (int i = 1; i < N; ++i) cars[i].b += cars[i-1].b;
	for (int i = 0; i < N; ++i) ans += 1LL*cars[i].a*cars[i].b; // Đừng quên là số to chetme nên phải nhân 1LL để tránh tràn số
	cout << ans << endl;
	for (int i = 0; i < N; ++i) cout << cars[i].index << " ";
	return 0;
}
