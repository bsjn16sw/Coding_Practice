// April 17, 2020

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_n = needle.length();
        if(!len_n)  return 0;
        
        int len_h = haystack.length();
        if(!len_h)  return -1;
        if(len_h < len_n)   return -1;
        
        for(int i=0; i<=len_h-len_n; i++){
            if(haystack[i] == needle[0]){
                bool valid = true;
                for(int j=0; j<len_n; j++){
                    if(haystack[i+j] != needle[j]){
                        valid = false;
                        break;
                    }
                }
                if(valid)   return i;
            }
        }
        
        return -1;

        /* Old solution: April 12, 2019
        int haylen = haystack.length();
        int nedlen = needle.length();
        
        // If needle is null, return 0.
        if(!nedlen) return 0;
        // If haystack is null and needle is not null,
        // haystack cannot include needle so return -1.
        if(!haylen) return -1;
        
        int i, j, iCopy;
        // Check haystack 0 to haylen-nedlen.
        // To include needle, maximum start index of substring
        // is haylen-nedlen.
        for(i=0; i<=haylen-nedlen; i++){
        	// iCopy means start index of current checking string.
        	// i can be change in next for-statement so copy it to iCopy.
            iCopy = i;
            // Check substring of haystack starting from index of iCopy
            // and needle. In this process, add i by 1.
            for(j=0; j<nedlen; j++){
                if(haystack[i] == needle[j])    i++;
                else    break;
            }
            // If previous for-statement is not 'break'ed,
            // j will have nedlen. That means substring of haystack
            // starting from index of iCopy and needle is same.
            if(j == nedlen) return iCopy;
            
            // If it is not, restore i by iCopy.
            // i will be add by 1 (i++ of for-statement).
            // So it will check substring starting from index of iCopy+1.
            i = iCopy;
        }
        
        return -1;
        */
    }
};
