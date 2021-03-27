using vi = vector<int>;
#define sz(x) int((x).size())

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vi> dp(sz(text1)+1,vi(sz(text2)+1,0));
		for (int i = 1; i <= sz(text1); ++i)  for (int j = 1; j <= sz(text2); ++j) {    
			if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
		return dp[sz(text1)][sz(text2)];
	}
};
//https://leetcode.com/problems/longest-common-subsequence/