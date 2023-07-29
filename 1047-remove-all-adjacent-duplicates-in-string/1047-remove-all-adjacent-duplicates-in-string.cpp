class Solution {
public:
    string removeDuplicates(string s) {
         string res;
        
        for(char ch : s){
            if(!res.empty() && res.back() == ch) res.pop_back();
            else res+=ch;
        }
        return res;
    }
};