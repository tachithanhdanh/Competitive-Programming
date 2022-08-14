class Solution {
public:
    using vi = vector<int>;
    #define sz(a) int((a).size())
    int pivotIndex(vi& nums) {
        int N = sz(nums);
        vi dp(N+2);
        for (int i = 1; i <= N; ++i) dp[i] = dp[i-1] + nums[i-1];
        dp[N+1] = dp[N];
        for (int i = 1; i <= N; ++i) if (dp[i-1] == dp[N+1]-dp[i]) return --i;
        return -1;
    }
};