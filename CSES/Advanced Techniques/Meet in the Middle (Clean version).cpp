#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> input(n);
	for (int &x: input) cin >> x;
	
	if (n == 1)
	{
		if (input[0] == x)
		{
			cout << 1 << "\n";
			return 0;
		}
		cout << 0 << "\n";
		return 0;
	}
 
	auto possible_sums = [&](vector<int>::iterator left, vector<int>::iterator right) {
		int n = right - left;
		vector<int> sums(1 << n);
		for (int mask = 0; mask < (1ll << n); mask++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					sum += left[i];
			sums[mask] = sum;
		}
		
		sort(sums.begin(), sums.end());
		return sums;
	};
	
	auto left_partition = possible_sums(input.begin(), input.begin() + input.size() / 2);
	auto right_partition = possible_sums(input.begin() + input.size() / 2, input.end());
	
	int count = 0;
	
	for (int sum: left_partition)
	{
		int companion = x - sum;
		auto left_bound = lower_bound(right_partition.begin(), right_partition.end(), companion);
		auto right_bound = upper_bound(right_partition.begin(), right_partition.end(), companion);
		count += right_bound - left_bound;
	}
	
	cout << count << "\n";
}
