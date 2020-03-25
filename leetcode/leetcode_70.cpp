// April 7, 2019
// March 25, 2020 (improved)

class Solution {
public:
    int climb(int n, int dp[]) {
        if(n == 1)  return 1;
        else if(n == 2) return 2;
        else if(dp[n] != 0) return dp[n];
        else    return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
    }
    
    int climbStairs(int n) {
        int dp[n + 1];
        for(int i=0; i<n+1; i++)
            dp[i] = 0;
        return climb(n, dp);
    }
};