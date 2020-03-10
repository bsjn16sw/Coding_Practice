// March 10, 2020
// Solution using unordered_map
// rf) https://leetcode.com/problems/roman-to-integer/discuss/214798/cpp-o(n)

class Solution {
public:
    int romanToInt(string s) {
        int num = 0, len = s.length();
        unordered_map<char, int> dict = \
            { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        
        for(int i=0; i<len; i++){
            if(i + 1 < len && dict[s[i]] < dict[s[i + 1]])
                num -= dict[s[i]];
            else
                num += dict[s[i]];
        }
        
        return num;
    }
};