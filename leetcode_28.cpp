class Solution {
public:
    int strStr(string haystack, string needle) {
        int haylen = haystack.length();
        int nedlen = needle.length();
        
        if(!nedlen) return 0;
        if(!haylen) return -1;
        
        int i, j, iCopy;
        for(i=0; i<=haylen-nedlen; i++){
            iCopy = i;
            for(j=0; j<nedlen; j++){
                if(haystack[i] == needle[j])    i++;
                else    break;
            }
            if(j == nedlen) return iCopy;
            i = iCopy;
        }
        
        return -1;
    }
};
