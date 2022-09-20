// Binary Indexed Tree (Fenwick Tree) 
template<class T>
struct Fenwick {
	int SZ;
	vector<T> bit;
	vector<T> arr;

	// All elements are one-indexed.
	Fenwick(int SIZE): SZ(SIZE), bit(SIZE + 1), arr(SIZE + 1) { }
	
	// Adds val to the element at index idx.
	void add(int idx, T val) {
		arr[idx] += val;
		for (; idx <= SZ; idx += idx & (-idx)) {
			bit[idx] += val;
		}
	}

	// Sets the value at index idx to val.
	void set(int idx, T val) {
		add(idx, val - arr[idx]);
	}

	// Return the sums of all value in [1, idx].
	T sum(int idx) {
		T ans = 0;
		for (; idx > 0; idx -= idx & (-idx)) {
			ans += bit[idx];
		}
		return ans;
	}
};
