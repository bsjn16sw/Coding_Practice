// March 8, 2020
// Solution using unordered_map
// rf) https://leetcode.com/problems/two-sum/discuss/536/My-simple-cpp-code

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsIndices;
        
        for(int i=0; i<nums.size(); i++){
            auto it = numsIndices.find(target - nums[i]);
            if(it != numsIndices.end())
                return vector<int>{it->second, i};
            else
                numsIndices.insert(make_pair(nums[i], i));
        }
        
        return vector<int>();
    }
};