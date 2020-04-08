// April 10, 2019 & April 2, 2020

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)    return 0;
        else if(len == 1)   return 1;

        int next_valid = 1;
        for(int i=1; i<len; i++){
            if(nums[next_valid-1] != nums[i]){
                if(i != next_valid) nums[next_valid] = nums[i];
                next_valid++;
            }
        }

        return next_valid;
    }
};
