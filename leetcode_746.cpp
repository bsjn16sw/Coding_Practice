class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        // Edge case: len is just 2.
        if(len == 2)    return min(cost[0], cost[1]);
        
        // Copy cost to cost2 and reverse it.
        // I copy it since cost is reference variable.
        vector<int> cost2 = cost;
        reverse(cost2.begin(), cost2.end());
        
        // mincost saves minimum cost to reach tail from
        // that index. Remember the vector is reversed.
        vector<int> mincost;
        // Enter base values.
        mincost.push_back(cost2[0]);
        mincost.push_back(cost2[1]);
        
        // Dynamic Programming.
        for(int i=2; i<len; i++)
            mincost.push_back(cost2[i] + min(mincost[i-1], mincost[i-2]));
        
        return min(mincost[len-1], mincost[len-2]);
    }
};
