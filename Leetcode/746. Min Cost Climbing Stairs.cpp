class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2);
        dp[0] = 0;
        for (int i = 1; i <= cost.size(); ++i) dp[i] = cost[i-1];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] += min(dp[i-1],dp[i-2]);
        }
        return dp.back();
    }
};