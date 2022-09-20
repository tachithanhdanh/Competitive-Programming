// Binary Indexed Tree (Fenwick Tree) 
template<class T>
struct Fenwick {
	int size;
	vector<T> bit;
	vector<T> arr;

	// All elements are one-indexed.
	Fenwick(int size): size(size), bit(size + 1), arr(size + 1) { }
	
	// Adds val to the element at index idx.
	void add(int idx, int val) {
		arr[idx] += val;
		for (; idx > 0; idx += idx & (-idx)) {
			bit[idx] += val;
		}
	}

	// Sets the value at index idx to val.
	void set(int idx, int val) {
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
}