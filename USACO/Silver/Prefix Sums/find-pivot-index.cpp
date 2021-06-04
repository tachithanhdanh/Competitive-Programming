class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size()+2);
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        for (int i = 1; i < nums.size() + 1; ++i) {
            if (prefix[i-1] == prefix[nums.size()] - prefix[i]) return i-1;
        }
        return -1;
    }
};