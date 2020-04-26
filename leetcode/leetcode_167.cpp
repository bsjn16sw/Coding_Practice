class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size() - 1;
        vector<int> indices;

        while(s < e){
            if(target - numbers[s] > numbers[e])  s++;
            else if(target - numbers[s] < numbers[e]) e--;
            else    break;
        }

        indices.push_back(s + 1);
        indices.push_back(e + 1);

        return indices;
    }
};