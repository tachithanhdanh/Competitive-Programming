#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

using ll = long long;

//vectors
using vi = vector<int>;
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define rsz resize
#define pb push_back

//pairs
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)

//constant initialization
const string yes="Yes",no="No";
const int MOD=1e9+7; //998244353
const int maxn=1e5+10;
const ll INF = 1e18; //Not too close to LLONG_MAX

//variables used for the current problem
int N, K, a1, a2, b1, b2, ans[101];
//Solution 1: http://www.usaco.org/current/data/sol_swap_bronze_feb20.html
int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	cin >> N >> K;
	cin >> a1 >> a2 >> b1 >> b2;
	auto next_position = [](int x) -> int {
		//Công thức tính vị trí của một số trong đoạn [x,y]
		//Gọi i là vị trí thứ i tính từ x đến y, vị trí đầu tiên trong đoạn có số thứ tự là 0 và vị trí cuối có số thứ tự là y-x
		//Vị trí thứ i có giá trị là x+i => vị trí của i sau khi swap là y-i
		//Ở đây thì ta có số A, để xác định nó có nằm trong đoạn [x,y] hay không thì ta sẽ có 2 yếu tố:
		//Đó là (x <= A && A <= y)
		//Nếu nó nằm trong đoạn đó thì số thứ tự của nó là A-x
		//=> Swap lại sẽ có vị trí là y-(A-x)
		if (a1 <= x && x <= a2) x = a2-(x-a1);
		if (b1 <= x && x <= b2) x = b2-(x-b1);
		return x;
	};
	FOR(i,1,N+1) {
		int period = 0, current_position = i;
		do {
			current_position = next_position(current_position);
			++period;
		} while (current_position != i);
		int k = K%period;
		F0R(j,k) current_position = next_position(current_position);
		ans[current_position] = i;
	}
	FOR(i,1,N+1) cout << ans[i] << endl;
	return 0;
}
