class Solution {
private:
    void braces(string &op, vector<string> &ans, int open, int close){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }
        
        if(open !=  0 ){
            string op1 = op;
            op1.push_back('(');
            braces(op1, ans, open-1, close);
        }
        if(open < close){
            string op2 = op;
            op2.push_back(')');
            braces(op2, ans, open, close-1);
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string> ans;
        string op ="";
        
        braces(op, ans, open, close);
        return ans;
    }
};