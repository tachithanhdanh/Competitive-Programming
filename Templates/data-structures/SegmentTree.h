// Cây phân đoạn có cập nhật lười (Segment Tree with Lazy Propagation)
// chỉ số bắt đầu từ 1
// ĐPT: xây dựng O(N), cập nhật O(log N), xử lí truy vấn O(log N).
// Nguồn: 
// - https://vnoi.info/wiki/algo/data-structures/segment-tree-basic.md#c%C3%A0i-%C4%91%E1%BA%B7t
// - https://usaco.guide/gold/PURS?lang=cpp#segment-tree
// - https://codeforces.com/contest/1696/submission/161757647
// Cách sử dụng:
//   Khai báo: 
//     SegTree ST(v);
//   Dùng hàm:
//     ST.update(vị trí cần cập nhật, giá trị);
//     ST.update(biên trái, biên phải, giá trị);
//     ST.get(biên trái, biên phải); (lấy giá trị trong [biên trái, biên phải])
//     ST.get(vị trí); (lấy giá trị của v[vị trí])
// Tự tinh chỉnh lại các phần sau đây mỗi khi làm bài tập
//   - struct node (bao gồm các biến và constructor, hàm apply)
//   - hàm unite, hàm push, pull, update, build
// verification: https://oj.vnoi.info/problem/segtree_itlazy
struct SegTree {
	struct node {
		// don't forget to set default value (used for leaves)
		// not necessarily neutral element!
		ll maxVal;
		ll lazyAdd;
		// default value for node
		node(): maxVal(-INF), lazyAdd(0) { }
		node(ll v): maxVal(v), lazyAdd(0) { }
		void apply(ll v) {
			maxVal += v;
			lazyAdd += v;
		}
	};

	// hàm unite phải có tính kết hợp (max, min, sum, __gcd, ...)
	node unite(const node& a, const node& b) {
		node res;
		ckmax(res.maxVal, max(a.maxVal, b.maxVal));
		return res;
	}
	
	void push(int id, int l, int r) {
		// only pushdown value to child nodes if it is not a leaf node
		if (l != r) {
			ll add = segtree[id].lazyAdd;
			segtree[id * 2].maxVal += add;
			segtree[id * 2 + 1].maxVal += add;
			segtree[id * 2].lazyAdd += add;
			segtree[id * 2 + 1].lazyAdd += add;
		}
		// set lazy value to 0
		segtree[id].lazyAdd = 0;
		return;
	}

	void pull(int id) {
		segtree[id] = unite(segtree[id * 2], segtree[id * 2 + 1]); 
	}

	int n;
	vector<node> segtree;

	SegTree(int _n) : n(_n) {
		assert(n > 0);
		segtree.resize(4 * n + 10);
		build(1, 1, n);
	}

	template <typename M>
	SegTree(const vector<M> &v, int SZ) {
		n = SZ;
		assert(n > 0);
		segtree.resize(4 * n + 10);
		build(1, 1, n, v);
	}


	// Thủ tục xây dựng cây phân đoạn
	void build(int id, int l, int r) {
		// Đoạn chỉ gồm 1 phần tử, không có nút con
		if (l == r) {
			segtree[id] = node(0);
			return;
		}

		// Gọi đệ quy để xử lý các nút con của nút id
		int mid = (l + r) >> 1; // (l + r) / 2
		build(id * 2, l, mid);
		build(id * 2 + 1, mid + 1, r);

		// Cập nhật lại giá trị của đoạn [l, r] theo 2 nút con (dựa theo hàm unite)
		pull(id);
	}

	template<typename M>
	void build(int id, int l, int r, const vector<M>& v) {
		// Đoạn chỉ gồm 1 phần tử, không có nút con
		if (l == r) {
			segtree[id] = node(v[l]);
			return;
		}

		// Gọi đệ quy để xử lý các nút con của nút id
		int mid = (l + r) >> 1; // (l + r) / 2
		build(id * 2, l, mid, v);
		build(id * 2 + 1, mid + 1, r, v);

		// Cập nhật lại giá trị của đoạn [l, r] theo 2 nút con (dựa theo hàm unite)
		pull(id);
	}

	// Thủ tục cập nhật
	template <typename M>
	void update(int pos, const M& val) {
		update(1, 1, n, pos, pos, val);
	}

	template <typename M>
	void update(int u, int v, const M& val) {
		update(1, 1, n, u, v, val);
	}

	template <typename M>
	void update(int id, int l, int r, int u, int v, const M& val) {
		// [u, v] nằm ngoài đoạn [l, r], ta bỏ qua nút id
		if (v < l || r < u) return;

		/* Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, 
			ta cập nhật lười ở nút id */
		if (u <= l && r <= v) {
			/* Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
			giá trị Lazy Propagation. Như vậy sẽ tránh sai sót. */
			segtree[id].apply(val);
			return;
		}

		int mid = (l + r) >> 1; // (l + r) / 2

		// Đẩy giá trị lazy của nút id xuống các nút con.
		push(id, l, r);

		// Gọi đệ quy để xử lý các nút con của nút id
		update(id * 2, l, mid, u, v, val);
		update(id * 2 + 1, mid + 1, r, u, v, val);

		// Cập nhật lại giá trị của đoạn [l, r] theo 2 nút con (dựa theo hàm unite)
		pull(id);
	}

	// Hàm lấy giá trị
	node get(int id, int l, int r, int u, int v) {
		// Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
		if (r < u || v < l) {
			return node();
		}
		
		/* Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, 
			ta trả lại thông tin lưu ở nút id */
		if (u <= l && r <= v) {
			return segtree[id];
		}

		int mid = (l + r) >> 1; // (l + r) / 2

		// Đẩy giá trị lazy của nút id xuống các nút con.
		push(id, l, r);

		// Gọi đệ quy với các nút con của nút id
		node get1 = get(id * 2, l, mid, u, v);
		node get2 = get(id * 2 + 1, mid + 1, r, u, v);

		// Trả ra giá trị của hàm comb theo 2 nút con
		return unite(get1, get2);
	}
	
	node get(int pos) {
		assert(1 <= pos && pos <= n);
		return get(1, 1, n, pos, pos);
	}
	
	node get(int u, int v) {
		assert(1 <= u && u <= v && v <= n);
		return get(1, 1, n, u, v);
	}
};
