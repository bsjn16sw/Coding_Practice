class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        string s2 = "";
        
        // Make string only have lower-case alphabet and number
        for(int i=0; i<len; i++){
            // Case 1: upper-case
            if(65 <= s[i] && s[i] <= 90)
                s2 += (s[i] + 32);
            // Case 2: lower-case, number
            else if((97 <= s[i] && s[i] <= 122) || (48 <= s[i] && s[i] <= 57))
                s2 += s[i];
        }
        
        int len2 = s2.length();
        if(!len2)   return true;
        
        // Check if s2 is palindrome
        for(int i=0; i<(len2/2); i++){
            if(s2[i] != s2[len2-1-i])    return false;
        }
        
        return true;
    }
};
