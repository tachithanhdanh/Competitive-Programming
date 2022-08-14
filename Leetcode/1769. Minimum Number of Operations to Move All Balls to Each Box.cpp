class Solution {
public:
    vector<int> minOperations(string boxes) {
        int N = boxes.size();
        vector<int> ans(N);
        vector<bool> pos(N);
        for (int i = 0; i < N; ++i) {
            if (boxes[i] == '1') pos[i] = true;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (pos[j]) ans[i] += abs(i-j);
            }
        }
        return ans;
    }
};