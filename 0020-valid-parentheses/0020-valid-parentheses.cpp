class Solution {
public:
    bool isValid(string s) { 
        stack<char> stk;
        for (char c:s) 
        {
            
            if(c =='(' || c == '[' || c == '{'){
                stk.push(c);
            }
            else {
                if(stk.empty()) return false;
                if(stk.top() != '(' && c == ')')
                    return false;
                if(stk.top() != '[' && c == ']')
                    return false;
                if(stk.top() != '{' && c == '}')
                    return false;
                stk.pop();
            }
        }  
        return stk.empty();   
    }
};