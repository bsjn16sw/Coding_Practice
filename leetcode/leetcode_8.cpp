class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        
        // Erase whitespaces in head.
        int i;
        for(i=0; i<len; i++){
            if(str[i] != ' ')   break;
        }
        str = str.substr(i, len-i);
        
        // If left string is null, that means
        // original string is composed of only
        // white spaces, return 0.
        len = str.length();
        if(!len)    return 0;
        
        int sign = 0, num = 0, rest = 0, val;
        // If first non-whitespace character is valid,
        // calculate it.
        if((int('0') <= str[0] && str[0] <= int('9')) || str[0] == '+' || str[0] == '-'){
            // If first non-whitespace character is
            // + or -, mark sign (initialized by 0)
            // and erase + or -.
            if(str[0] == '+')
                str = str.substr(1, --len);
            else if(str[0] == '-'){
                sign = 1;
                str = str.substr(1, --len);
            }
            
            // If it is positive number.
            if(sign == 0){
                // rest means digit in ones place of INT_MAX.
                // It will be used to deal with potential overflow.
                rest = INT_MAX % 10;
                for(int j=0; j<len; j++){
                    // If the char is not digit, break.
                    if(int('0') > str[j] || str[j] > int('9'))  break;
                    // Convert char to int.
                    // val is absolutely needed. If there is no val and
                    // just use str[j] - int('0'), overflow can be occured
                    // in line 51. (num * 10 + str[j] can cause overflow.)
                    val = str[j] - int('0');
                    // Deal with potential overflow.
                    if(num > INT_MAX / 10 || ((num == INT_MAX / 10) && val > rest)){
                        return INT_MAX;
                    }
                    
                    num = num * 10 + val;
                }
            }
            // If it is negative number.
            // The code below is similar with above code but
            // if it use positive number and negate it in last,
            // it can cause overflow.
            else{
                rest = -(INT_MIN % 10);
                for(int j=0; j<len; j++){
                    if(int('0') > str[j] || str[j] > int('9'))  break;
                    val = str[j] - int('0');
                    if(num < INT_MIN / 10 || ((num == INT_MIN / 10) && val > rest)){
                        return INT_MIN;
                    }
                    num = num * 10 - val;
                }
            }
            
            return num;
        }
        // If not, return 0.
        else    return 0;
    }
};
