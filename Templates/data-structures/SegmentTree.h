// Cây phân đoạn (Segment Tree)
// chỉ số bắt đầu từ 1
// ĐPT: xây dựng O(N), cập nhật O(log N), xử lí truy vấn O(log N).
// Nguồn: 
// - https://vnoi.info/wiki/algo/data-structures/segment-tree-basic.md#c%C3%A0i-%C4%91%E1%BA%B7t
// - https://usaco.guide/gold/PURS?lang=cpp#segment-tree
template<typename T, const T DEFAULT>
struct SegTree {
	// Phải tự viết lại hàm trong đây vì template không truyền được con trỏ hàm
	//   https://stackoverflow.com/a/36945951
	// hàm comb phải có tính kết hợp (max, min, sum, __gcd, ...)
	T comb(const T& T1, const T& T2) {
		return (T1 + T2); 
		// return max<T>(T1, T2); 
		// return min<T>(T1, T2); 
		// return __gcd<T>(T1, T2);
	}

	// https://stackoverflow.com/questions/1828037/whats-the-point-of-g-wreorder
	int n;
	vector<T> a;
	vector<T> segtree;

	SegTree(int LEN): n(LEN), a(LEN + 1), segtree(LEN * 4 + 10, DEFAULT) { }

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

	// Thủ tục cập nhật
	void update(int pos, int val) {
		update(1, 1, n, pos, val);
	}

	void update(int id, int l, int r, int pos, int val) {
		// i nằm ngoài đoạn [l, r], ta bỏ qua nút id
		if (pos < l || r < pos) return;

		// Đoạn chỉ gồm 1 phần tử, không có nút con
		if (l == r) {
			segtree[id] = val;
			return;
		}

		// Gọi đệ quy để xử lý các nút con của nút id
		int mid = (l + r) >> 1; // (l + r) / 2
		update(id * 2, l, mid, pos, val);
		update(id * 2 + 1, mid + 1, r, pos, val);

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

		// Trả ra giá trị nhỏ nhất theo 2 nút con
		return comb(get1, get2);
	}
};
