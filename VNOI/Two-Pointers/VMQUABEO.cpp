/**
 *    author:    tachithanhdanh
 *    created:   2022-09-10    14:26:10
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

// Ý tưởng 2 con trỏ
// tạo 1 multiset lưu giữ các giá trị từ H[l] đến H[r]
// bây giờ ở phần xử lí đầu tiên
// gọi delta = max(H(l, r)) - min(H(l, r))
// trong TH delta > D
// thì khi đó chúng ta sẽ trượt con trỏ l 
// cho đến khi delta <= D
// rồi sau đó đến phần xử lí thứ 2
// nếu r - l >= L (tức là đoạn từ l đến r có độ dài >= L)
// thì ta sẽ cộng đáp án thêm số đoạn con kết thúc tại end = r và bắt đầu tại start >= l
// sao cho end - start vẫn >= L (tức là đoạn con có độ dài >= L)
// lí giải cho việc tại sao các đoạn con [l, r] đúng thì các đoạn con [l+1, r], [l+2, r], ... [r-L, r] vẫn đúng (lưu ý đoạn con cuối có độ dài r - (r - L) = L) 
// thì ta có thể hiểu là
// khi rút ngắn 1 phần tử ở biên trái đoạn con (gọi là val)
// có 3 TH xảy ra
// 1. val không phải max đoạn cũng không phải min đoạn, khi đó delta không đổi nên đoạn con mới này vẫn thỏa (delta vẫn <= D và độ dài vẫn >= L)
// 2. val là max đoạn, khi đó delta sẽ giảm đi vì new_max < max nên new_max - min < max - min => new_delta < delta <= D
// 3. val là min đoạn, khi đó delta cũng giảm đi vì 
// 	new_min > min nên - new_min < - min => max - new_min < max - min => new_delta < delta <= D 
// vậy ta đã chứng minh được qua 3 TH thì đoạn con đó vẫn thỏa
// vì vậy ta chỉ cần đếm các đoạn con có start >= l và end = r cộng thêm điều kiện end - start >= L
// nghĩa là start sẽ có giá trị từ l đến r - L, vậy ta có r - L - l + 1 đoạn thỏa mãn
	
void solve() {
	int N, L, D;
	cin >> N >> L >> D;
	multiset<int> m;
	vi H(N);
	for(int& h: H) cin >> h;
	ll ans = 0;
	for (int l = 0, r = 0; r < N; ++r) {
		m.insert(H[r]);
		while (*m.rbegin() - *m.begin() > D) {
			auto it = m.find(H[l]);
			m.erase(it);
			++l;
		}
		if (r - l >= L) {
			ans += r - (l + L) + 1;
		}
	}
	cout << ans << endl;
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