// April 7, 2020

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len == 0)    return 0;

        int valid_next = 0;
        for(int i=0; i<len; i++){
            if(nums[i] != val){
                nums[valid_next] = nums[i];
                valid_next++;
            }
        }

        return valid_next;
    }

    /* Old solution: April 10, 2019
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len == 0)    return 0;
        
        sort(nums.begin(), nums.end());
        
        int enter = 0;
        int count = 0;
        int i, j, k;
        
        // Find first val.
        for(i=0; i<len; i++){
            if(nums[i] != val) enter++;
            else break;
        }
        
        // Edge case: no val
        if(i == len)    return len;
        
        // Find first different elem after vals.
        for(j=i; j<len; j++){
            if(nums[j] != val) break;
            else count++;
        }
        
        // Copy from j to end.
        for(k=j; k<len; k++){
            nums[enter] = nums[k];
            enter++;
        }
        
        nums.resize(len - count);
        return len - count;
    }
};
