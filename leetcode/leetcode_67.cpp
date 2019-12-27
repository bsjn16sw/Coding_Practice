class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();
        int posA = lenA - 1, posB = lenB - 1, carry = 0, val = 0, temp;
        string binSum = "";
        
        // From digit in ones place, add two digit and carry.
        // Carry is reflected in next phase.
        while(posA >= 0 || posB >= 0){
            if(posA < 0)
                temp = b[posB] + carry - '0';
            else if(posB < 0)
                temp = a[posA] + carry - '0';
            else
                temp = a[posA] + b[posB] + carry - (2 * '0');
            
            if(temp >= 2){
                carry = 1;
                val = temp - 2;
            }
            else{
                carry = 0;
                val = temp;
            }

            binSum += to_string(val);
            
            posA--;
            posB--;
        }
        
        // Last carry did not considered in while-loop.
        // So checking carry is necessary.
        if(carry)   binSum = binSum + "1";

        // Reverse the string
        reverse(binSum.begin(), binSum.end());
        
        return binSum;
    }
};
