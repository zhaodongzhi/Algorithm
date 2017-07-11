class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0, buy=INT_MIN, do_nothing=0;
        for(int i=0; i<prices.size(); ++i)
        {
            int s_old = sell;
            sell = max(buy+prices[i], sell);
            buy = max(do_nothing-prices[i], buy);
            do_nothing = s_old;
        }
        return sell;
    }
};
