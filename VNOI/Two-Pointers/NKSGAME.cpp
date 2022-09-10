/**
 *    author:    tachithanhdanh
 *    created:   2022-09-10    09:30:14
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#endif

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
const bool multitest = false;

void solve() {
	int n;
	cin >> n;
	vi b(n), c(n);
	for (int& bb: b) cin >> bb;
	for (int& cc: c) cin >> cc;
	
	// sort b tăng dần (thật ra là không giảm nhưng viết như vậy cho dễ hình dung)
	sort(all(b)); 

	//  sort c giảm dần (thật ra là không tăng nhưng viết như vậy cho dễ hình dung)
	sort(all(c), greater<int>());
	int minSum = 2 * MOD;
	for (int i = 0, j = 0; i < n && j < n;) {
		int curSum = b[i] + c[j];
		if (curSum < 0) {
			// nếu số đó âm có nghĩa là thằng b[i] đang quá nhỏ
			// tăng i lên để tổng b[i] và c[j] sẽ lớn hơn (b là mảng tăng dần)
			// với hi vọng là tổng mới sẽ tiến về số 0 (who knows)
			// nếu tổng tiếp theo (ở lần lặp kế tiếp) lớn hơn 0 thì xem ở TH 2
			// xuống cuối vòng lặp có note
			ckmin(minSum, abs(curSum));
			++i;
		}
		else if (curSum > 0) {
			// nếu số dương có nghĩa là thằng c[j] đang quá lớn
			// cần tăng j vì c là mảng giảm dần
			// tăng j lên để tổng b[i] là c[j] nó sẽ lùi về số 0 (tức là tổng nhỏ hơn)
			// với hi vọng là tổng mới sẽ lùi về số 0 (who knows)
			// nếu tổng tiếp theo (ở lần lặp kế tiếp) nhỏ hơn 0 thì xem ở TH 1
			// xuống cuối vòng lặp có note
			ckmin(minSum, abs(curSum));
			++j;
		}
		else {
			minSum = 0; break;
		}
		// ta cứ lặp như vậy mãi để tìm tổng nhỏ nhất trong tất cả các tổng
		// cho đến khi tìm được tổng bằng 0 (tức là tổng nhỏ nhất có thể)
		// hoặc là khi ta đã duyệt hết 1 trong 2 mảng (hoặc cả hai)
	}
	cout << minSum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif // LOCAL
	int tt = 1;
	if (multitest) cin >> tt;
	for (int t = 0; t < tt; ++t) {
		solve();
	}
	return 0;
}