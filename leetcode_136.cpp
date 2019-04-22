class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0; i<len; i+=2){
            if(i+1 >= len)              return nums[i];
            if(nums[i] != nums[i+1])    return nums[i];
        }
        return 0;
    }
};
