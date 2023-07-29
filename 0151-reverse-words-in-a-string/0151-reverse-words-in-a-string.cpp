class Solution {
public:
    string reverseWords(string s) {
      stack<string> st;
        string temp = "";
        for(auto x: s){
            if(x== ' '){
                if(temp.size() > 0) 
                    st.push(temp);
                temp ="";
            }
            else{
                temp.push_back(x);
            }
        }
        if(temp.size() > 0)
           st.push(temp);
        temp ="";
        while(st.size() > 1){
            temp += st.top() +" ";
            st.pop();
        }
        
        temp += st.top();
        return temp;
    }
};