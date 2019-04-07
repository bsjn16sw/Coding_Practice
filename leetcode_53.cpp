class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // tmp is currently maximum number and
        // max is globally maximum number
        int tmp = 0, max = 0;
        // neg will convert to 0
        // when there is at least one positive number.
        int neg = 1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) neg = 0;
            tmp += nums[i];
            if(tmp > max)   max = tmp;
            else if(tmp < 0)    tmp = 0;
        }
        
        // When all elements are negative,
        // the biggest number in nums is the answer.
        if(neg){
            max = INT_MIN;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] > max)   max = nums[i];
            }
        }
        
        return max;
    }
};
