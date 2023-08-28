class Solution {
public:
    string sortSentence(string s) {
        int n = 1;
        for(auto ch: s) if(ch == ' ') n++;
        // cout<< n;
        
        vector<string> ans(n);
        string temp ="";
        for(auto it: s){
            if(it != ' ')
                temp += it;
            else
            {
                int num = temp.back() -'0';
                temp.pop_back();
                ans[num-1]= temp;
                temp ="";
            }
        }
        int num = temp.back() -'0';
        temp.pop_back();
        ans[num-1]= temp;
        temp ="";
        string res;
        for(auto it: ans){
            res += it + " ";
        }
        res.pop_back();
        return res;
    }
};