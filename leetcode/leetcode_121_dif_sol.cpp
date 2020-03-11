// March 11, 2020
// Solution that updates max_profit right away.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        
        int min = prices[0], max = prices[0], max_profit = 0;
        for(int i=1; i<len; i++){
            if(prices[i] < min){
                min = prices[i];
                max = prices[i];
            }
            else if(prices[i] > max){
                max = prices[i];
                if(max - min > max_profit)
                    max_profit = max - min;
            }
        }
        
        return max_profit;
    }
};