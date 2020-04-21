class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        int len, num;
        char prev;
        for(int i=2; i<=n; i++){
            len = s.length();
            prev = s[0];
            num = 1;
            string s2 = "";
            
            for(int j=1; j<=len; j++){
                if(prev != s[j] || j == len){
                    s2 += ('0' + num);
                    s2 += prev;
                    
                    prev = s[j];
                    num = 1;
                }
                else if(prev == s[j])   num++;
            }
            
            s = s2;
        }
        
        return s;
    }
};