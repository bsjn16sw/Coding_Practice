// April 2, 2019 & March 8, 2020

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result;
        
        vector<pair<int, int>> numsIndices;
        pair<int, int> numIndex;
        for(int i=0; i<nums.size(); i++){
            numIndex = make_pair(nums[i], i);
            numsIndices.push_back(numIndex);
        }
        
        sort(numsIndices.begin(), numsIndices.end());
        while(left < right){
            if(target - numsIndices[left].first < numsIndices[right].first){
                right--;
            }
            else if(target - numsIndices[left].first > numsIndices[right].first){
                left++;
            }
            else{
                result.push_back(numsIndices[left].second);
                result.push_back(numsIndices[right].second);
                break;
            }
        }
        
        return result;
    }

    /* Different solution using unordered_map
    -> https://leetcode.com/problems/two-sum/discuss/536/My-simple-cpp-code

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
    */
};
