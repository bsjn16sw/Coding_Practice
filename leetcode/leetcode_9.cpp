// April 7, 2019
// March 10, 2020 (review)

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        else if(x == 0) return true;
        
        string org = to_string(x);
        string rev(org);
        
        reverse(rev.begin(), rev.end());
        /*int len = org.length();
        for(int i=0; i<len; i++){
            rev[i] = org[len - i - 1];
        }*/
        
        if(!org.compare(rev))   return true;
        else    return false;
    }
};
