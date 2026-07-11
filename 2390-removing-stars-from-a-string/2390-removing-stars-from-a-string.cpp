class Solution {
public:
    string removeStars(string s) {
        stack<char>stk;
        string op="";
        for (char c : s){
            if(c != '*'){
                stk.push(c);
            }
            else {
                stk.pop();
            }
        }
        while(!stk.empty()){
            op+=stk.top();
            stk.pop();
        }
        reverse(op.begin(),op.end());
        return op;
    }
};