class Solution {
public:
    int sum[10], ans = INT_MAX;
    void dfs (int n, const int& k, const vector<int>& cookies) {
        if (n == cookies.size()) {
            ans = min(ans,*max_element(sum,sum+10));
            return;
        }
        for (int i = 0; i < k; ++i) {
            sum[i] += cookies[n];
            dfs(n+1,k,cookies);
            sum[i] -= cookies[n];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        //dp[k][n] = min(dp[k-1][n],dp[k][n-1]+cookies[n]);
        //dp[1][n] = dp[1][n-1]+cookies[n];
        dfs(0,k,cookies);
        return ans;
    }
};