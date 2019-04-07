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
};
