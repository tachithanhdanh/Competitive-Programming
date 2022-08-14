const int MOD = 1e9+7; //998244353
class Solution {
public:
	int countVowelPermutation(int n) {
		vector<vector<int>> dp(6,vector<int>(n+1));
		for (int i = 1; i <= 5; ++i) dp[i][1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= 5; ++j) {
				if (j == 1) (dp[1][i] += (dp[2][i-1] + dp[3][i-1])%MOD + dp[5][i-1]) %= MOD;
				if (j == 2) (dp[2][i] += dp[1][i-1] + dp[3][i-1]) %= MOD;
				if (j == 3) dp[3][i] += (dp[2][i-1] + dp[4][i-1])%MOD;
				if (j == 4) (dp[4][i] += dp[3][i-1]) %= MOD;
				if (j == 5) (dp[5][i] += dp[4][i-1] + dp[3][i-1]) %= MOD;
			}
		}
		int ans = 0;
		for (int i = 1; i <= 5; ++i) (ans += dp[i][n]) %= MOD;
		return ans; 
	}
};