class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int in = numeric_limits<int>::max();
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++){
            in = min(in,prices[i]);
            profit = max(profit,prices[i]-in);
        }
        
        return profit;
    }
};
