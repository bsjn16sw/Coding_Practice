class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if(!len)    return 0;
        
        // Remove white spaces in the head.
        int i, j;
        for(i=0; i<len; i++){
            if(s[i] != ' ') break;
        }
        s = s.substr(i, len-i);
        
        // Reverse the string and
        // remove white spaces in the tail.
        reverse(s.begin(), s.end());
        for(j=0; j<len-i; j++){
            if(s[j] != ' ') break;
        }
        s = s.substr(j, len-i-j);
        
        // Get changed length of string.
        len = s.length();
        if(!len)    return 0;
        
        // Count the length of word before
        // before first space appears.
        // Remember I reverse the string.
        int cnt = 0;
        for(i=0; i<len; i++){
            if(s[i] != ' ') cnt++;
            else    break;
        }
        
        return cnt;
    }
};
