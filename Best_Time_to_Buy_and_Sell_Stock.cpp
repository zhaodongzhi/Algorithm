class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MIN, sell1=0;
        for(int i=0; i<prices.size(); ++i)
        {
            sell1 = max(buy1+prices[i], sell1);
            buy1 = max(-prices[i], buy1);
        }
        return sell1;
    }
};
