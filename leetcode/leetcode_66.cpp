class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // If interpreting digits to number data type
        // (e.g. int, long), upper bound will always exist.
        // So do not interpret it and just calculate
        // digit by digit using carry.
        
        int len = digits.size();
        int carry = 0, val = 0, cursum = 0;
        vector<int> sum;
        
        // Use carry.
        cursum = digits[len-1] + 1;
        if(cursum >= 10){
            carry = 1;
            sum.push_back(0);
        }
        else{
            sum.push_back(cursum);
        }
        
        for(int i=len-2; i>=0; i--){
            cursum = digits[i] + carry;
            if(cursum >= 10){
                carry = 1;
                sum.push_back(0);
            }
            else{
                carry = 0;
                sum.push_back(cursum);
            }
        }
        
        // Remember remaining carry must be
        // considered!!!
        if(carry)   sum.push_back(carry);
        
        // Reverse vector sum.
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};
