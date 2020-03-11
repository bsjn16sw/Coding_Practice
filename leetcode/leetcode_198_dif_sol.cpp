// March 11, 2020

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        // Edge cases
        if(len == 0)    return 0;
        else if(len == 1)   return nums[0];
        
        // Set up first 2 elem of profits.
        vector<int> profits;
        profits.push_back(nums[0]);
        if(nums[0] < nums[1])
            profits.push_back(nums[1]);
        else
            profits.push_back(nums[0]);
        
        // Edge case
        if(len == 2)    return profits.back();
        
        // profits[i] means the maximum profit
        // when robber considers house[0] to house[i].
        // Since he must not include two adjacent houses,
        // profits[i] will be max(profits[i-2] + nums[i], profits[i-1]).
        for(int i=2; i<len; i++)
            profits.push_back(max(profits[i-2] + nums[i], profits[i-1]));
        
        return profits.back();
    }
};