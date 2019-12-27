class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int len = nums.size();
        
        for(int i=0; i<len; i++){
            auto j = m.find(nums[i]);
            if(j != m.end())    m[nums[i]] += 1;
            else                m.insert(make_pair(nums[i], 1));
        }

        for(auto i=m.begin(); i != m.end(); i++){
            if((i -> second) > len/2)  return i -> first;
        }
        
        return nums[0];
    }
};
