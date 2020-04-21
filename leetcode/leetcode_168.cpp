class Solution {
public:
    string convertToTitle(int n) {
        string title = "";
        
        int q, r;
        while(true){
            q = n / 26;
            r = n % 26;
            
            if(!r){
                q--;
                r += 26;
            }
            title += 'A' + r - 1;
            
            if(!q)  break;
            if(q <= 26){
                title += 'A' + q - 1;
                break;
            }
            else    n = q;
        }
        
        reverse(title.begin(), title.end());
        return title;
    }
};