class Solution {
public:
    bool bracketCheck(char a, char b){
        if(a == ')' || a == '}' || a == ']')
            return false;
        
        if(a == '(' && b == ')')
            return true;
        else if(a == '{' && b == '}')
            return true;
        else if(a == '[' && b == ']')
            return true;
        else return false;
    }
    
    bool isValid(string s) {
        int len = s.length();
        // If s is empty string, return true.
        if(!len) return true;
        
        // Use stack to check validity.
        stack<char> stk;
        bool valid = true;
        for(int i=0; i<len; i++){
            // If it is opening parentheses, push it to stack.
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            // If it is closing parentheses..
            else{
                // If the stack is empty, return false.
                if(stk.empty()){
                    valid = false;
                    break;
                }
                // If reach to this point, stack is not empty.
                // Call procedure to check element of stack top and
                // s[i] matches correctly.
                if(!bracketCheck(stk.top(), s[i])){
                    valid = false;
                    break;
                }
                // If bracketCheck returns true,
                // continue the check process after pop.
                else stk.pop();
            }
        }
        // If there remains any element in stack,
        // it means there was a opening paren but
        // there was no closing paren so return false.
        if(stk.size()) valid = false;
        
        return valid;        
    }
};
