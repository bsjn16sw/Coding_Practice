// April 7, 2019 & March 10, 2020

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int len = s.length();
        
        for(int i=0; i<len; i++){
            if(s[i] == 'I'){
                if(i + 1 < len){
                    if(s[i + 1] == 'V'){
                        num += 4;
                        i++;
                    }
                    else if(s[i + 1] == 'X'){
                        num += 9;
                        i++;
                    }
                    else    num += 1;
                }
                else    num += 1;
            }
            else if(s[i] == 'V')    num += 5;
            else if(s[i] == 'X'){
                if(i + 1 < len){
                    if(s[i + 1] == 'L'){
                        num += 40;
                        i++;
                    }
                    else if(s[i + 1] == 'C'){
                        num += 90;
                        i++;
                    }
                    else    num += 10;
                }
                else    num += 10;
            }
            else if(s[i] == 'L')    num += 50;
            else if(s[i] == 'C'){
                if(i + 1 < len){
                    if(s[i + 1] == 'D'){
                        num += 400;
                        i++;
                    }
                    else if(s[i + 1] == 'M'){
                        num += 900;
                        i++;
                    }
                    else    num += 100;
                }
                else    num += 100;
            }
            else if(s[i] == 'D')    num += 500;
            else    num += 1000;
        }
        
        return num;
    }

    /* Different solution with unordered_map
    -> https://leetcode.com/problems/roman-to-integer/discuss/214798/cpp-o(n)

    int romanToInt(string s) {
        int num = 0, len = s.length();
        unordered_map<char, int> dict = \
            { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        
        for(int i=0; i<len; i++){
            if(i + 1 < len && dict[s[i]] < dict[s[i+1]])
                num -= dict[s[i]];
            else
                num += dict[s[i]];
        }
        
        return num;
    }
    */
};