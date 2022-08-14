class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // 9*9 = 81
        vector<vector<int>> sums(100);
        for (int& num : nums) {
            int sum = 0, n = num;
            while (n) {
                sum += n%10;
                n /= 10;
            }
            sums[sum].push_back(num);
            //cout << sum << " " << num << endl;
        }
        for (int i = 0; i < 100; ++i) {
            sort(sums[i].begin(),sums[i].end());
        }
        int ans = -1;
        for (int i = 0; i < 100; ++i) {
            if (sums[i].size() < 2) continue;
            ans = max(ans,sums[i][sums[i].size()-2]+sums[i].back());
        }
        return ans;
    }
};