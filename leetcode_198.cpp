class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        int max = 0;
        
        // Edge cases: when len is 0 to 2.
        if(len == 0)    return 0;
        else if(len == 1)   return nums[0];
        else if(len == 2){
            max = nums[0];
            if(nums[1] > max)
                max = nums[1];
            return max;
        }
        
        // tmpMax[i] means, maximum profit
        // when house i is absolutely included and
        // some houses range in i+1 ~ len-1 are included
        // selectly to maximize profit.
        int tmpMax[len];
        
        tmpMax[len-1] = nums[len-1];
        tmpMax[len-2] = nums[len-2];
        
        for(int i=len-3; i>=0; i--){
            max = tmpMax[i+2];
            for(int j=i+3; j<=len-1; j++){
                if(tmpMax[j] > max)
                    max = tmpMax[j];
            }
            tmpMax[i] = nums[i] + max;
        }
        
        max = tmpMax[0];
        for(int i=1; i<len; i++){
            if(tmpMax[i] > max)
                max = tmpMax[i];
        }
        
        return max;
    }
};
