class Solution {
public:
    int fillCups(vector<int>& amount) {
        int turns = 0;
        sort(amount.begin(),amount.end());
        while(amount[2]) {
            if (amount.back() && amount[1]) --amount[2], --amount[1];
            else if (amount[2]) --amount[2];
            ++turns;
            sort(amount.begin(),amount.end());
        } 
        return turns;
    }
};