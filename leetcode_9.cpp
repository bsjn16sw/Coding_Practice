class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        else if(x == 0) return true;
        
        string org = to_string(x);
        string rev(org);
        
        int len = org.length();
        for(int i=0; i<len; i++){
            rev[i] = org[len - i - 1];
        }
        
        if(!org.compare(rev))   return true;
        else    return false;
    }
};
