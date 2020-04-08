// March 11, 2020

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
    
    /* Old solution: April 7, 2019
    int maxProfit(vector<int>& prices) {
        vector<int> v_sell;
        int sell = 0;
        
        // For each day D, best day to sell stock is
        // day which has maximum price 'after the day D'.
        // For this, calculate current maximum price
        // from tail of vector prices.
        for(int i=prices.size()-1; i>=0; i--){
            if(prices[i] > sell)    sell = prices[i];
            v_sell.push_back(sell);
        }
        // Reverse the vector to calculate profit easily.
        reverse(v_sell.begin(), v_sell.end());
        
        // Calculate maximum profit.
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            if(v_sell[i] - prices[i] > maxProfit)
                maxProfit = v_sell[i] - prices[i];
        }
        
        return maxProfit;
    }*/
};
