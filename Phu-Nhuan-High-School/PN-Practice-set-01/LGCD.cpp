/**
 *    author:    tachithanhdanh
 *    created:   2022-09-24    11:01:46
**/

#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

#ifdef LOCAL
#include "debugging.h"
#else
#define db(x) 42
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
const bool multitest = true == false;

// Cây phân đoạn (Segment Tree)
// chỉ số bắt đầu từ 1
// ĐPT: xây dựng O(N), cập nhật O(log N), xử lí truy vấn O(log N).
// Nguồn: 
// - https://vnoi.info/wiki/algo/data-structures/segment-tree-basic.md#c%C3%A0i-%C4%91%E1%BA%B7t
// - https://usaco.guide/gold/PURS?lang=cpp#segment-tree
// Cách sử dụng:
//   Khai báo: 
//     Định nghĩa hàm lambda nào đó: auto comb = []() {};
//     SegTree<T, value> ST(SIZE, comb);
//   Dùng hàm:
//     ST.build(1, 1, SIZE); (xây dựng cây phân đoạn)
//     ST.update(vị trí cần cập nhật, giá trị);
//     ST.get(biên trái, biên phải); (lấy giá trị trong [biên trái, biên phải])
template<typename T, const T DEFAULT>
struct SegTree {
	// hàm comb phải có tính kết hợp (max, min, sum, __gcd, ...)
	function<T(const T&, const T&)> comb;

	int n;
	vector<T> a;
	vector<T> segtree;

	SegTree(int LEN, function<T(const T&, const T&)> c): 
		comb(c), n(LEN), a(LEN + 1), segtree(LEN * 4 + 10, DEFAULT) { }

	// Thủ tục xây dựng cây phân đoạn
	void build(int id, int l, int r) {
		// Đoạn chỉ gồm 1 phần tử, không có nút con
		if (l == r) {
			segtree[id] = a[l];
			return;
		}

		// Gọi đệ quy để xử lý các nút con của nút id
		int mid = (l + r) >> 1; // (l + r) / 2
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);

		// Cập nhật lại giá trị của đoạn [l, r] theo 2 nút con (dựa theo hàm comb)
		segtree[id] = comb(segtree[id * 2], segtree[id * 2 + 1]); 
	}

	// Hàm lấy giá trị
	T get(int u, int v) {
		return get(1, 1, n, u, v);
	}

	T get(int id, int l, int r, int u, int v) {
		// Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
		if (r < u || v < l) {
			return DEFAULT;
		}
		
		/* Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, 
			ta trả lại thông tin lưu ở nút id */
		if (u <= l && r <= v) {
			return segtree[id];
		}

		// Gọi đệ quy với các nút con của nút id
		int mid = (l + r) >> 1; // (l + r) / 2
		T get1 = get(id * 2, l, mid, u, v);
		T get2 = get(id * 2 + 1, mid + 1, r, u, v);

		// Trả ra giá trị của hàm comb theo 2 nút con
		return comb(get1, get2);
	}
};

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	auto GCD = [](const ll& a, const ll& b) -> ll { 
		if (a == 0) return b;
		if (b == 0) return a;
		return gcd<ll, ll>(a, b); 
	};
	SegTree<ll, 0LL> tree(n, GCD);
	for (int i = 1; i <= n; ++i) cin >> tree.a[i];
	tree.build(1, 1, n);
	int ans = 0;
	ll cur;
	for (int l = 1, r = 1; r <= n; ++r) {
		cur = tree.get(l, r);
		while (l < r && cur < k) {
			++l;
			cur = tree.get(l, r);
		}
		if (cur == k) ckmax(ans, r - l + 1);
	}
	cout << ans;
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