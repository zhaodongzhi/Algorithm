class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size()/2)
        {
            int result = 0;
            for(int i=1; i<prices.size(); ++i)
            {
                result += max(prices[i]-prices[i-1], 0);
            }
            return result;
        }
        
        vector<int> buys(k+1, INT_MIN);
        vector<int> sells(k+1, 0);
        for(int i=0; i<prices.size(); ++i)
        {
            int price = prices[i];
            for(int j=k; j>0; --j)
            {
                sells[j] = max(buys[j]+price, sells[j]);
                buys[j] = max(sells[j-1]-price, buys[j]);
            }
        }
        return sells[k];
    }
};
