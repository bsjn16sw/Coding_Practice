// March 25, 2020
// Un-recursive solution

class Solution {
public:
    int climbStairs(int n) {
        int dp[n + 1];
        
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else{
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 2;
            
            for(int i=3; i<n+1; i++)
                dp[i] = dp[i - 1] + dp[i - 2];
            
            return dp[n];
        }
    }
};