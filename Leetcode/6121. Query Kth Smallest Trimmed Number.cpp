class Solution {
public:
    // Time complexity: O(Q*N*(S+logN))
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        for (vector<int>& query : queries) {
            int k = query[0]-1, trim = query[1];
            vector<pair<string,int>> ans;
            for (int i = 0; i < nums.size(); ++i) {
                ans.push_back(make_pair(nums[i].substr(nums[i].size()-trim),i));
            }
            sort(ans.begin(),ans.end(),[](const pair<string,int>& a, const pair<string,int>& b) {
                if (a.first < b.first) return true;
                if (a.first == b.first) return a.second < b.second;
                return false;
            });
            answer.push_back(ans[k].second);
        }
        return answer;
    }
};