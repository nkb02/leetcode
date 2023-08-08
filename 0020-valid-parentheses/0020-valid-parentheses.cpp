class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';
        
        for(auto x: s){
            if(x == '(' || x == '{' || x == '[')
                st.push(x);
            else{
                if(st.empty() || st.top() != mp[x])
                    return false;
                
                st.pop();
            }
        }
        
        if(st.empty()) return true;
        
        return false;
    }
};