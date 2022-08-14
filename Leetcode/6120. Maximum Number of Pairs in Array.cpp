class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(101);
        for (int& i : nums) ++cnt[i];
        vector<int> ans(2);
        for (int& n : cnt) ans[0] += n/2, ans[1] += n%2;
        return ans;
    }
};