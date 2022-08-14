class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> vp;
        int fn = nums[0], cnt = 0;
        for (int& n : nums) {
            if (n == fn) ++cnt;
            else {
                vp.push_back(make_pair(fn,cnt));
                fn = n;
                cnt = 1;
            }
        }
        int op = 0;
        vp.push_back(make_pair(fn,cnt));
        for (int i = 0; i < vp.size(); ++i) {
            fn = vp[i].first;
            bool flag = true;
            for (int& n : numsDivide) {
                if (n % fn) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return op;
            }
            else {
                op += vp[i].second;
            }
        }
        return -1;
    }
};