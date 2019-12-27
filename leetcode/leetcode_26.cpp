class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 0)    return 0;
        else if(len == 1)   return 1;
        
        int enter = 1; // position to enter new value
        for(int i=1; i<len; i++){
            if(nums[enter-1] != nums[i]){
                nums[enter] = nums[i];
                enter++;
            }
        }
        
        nums.resize(enter);
        return enter;
    }
};
