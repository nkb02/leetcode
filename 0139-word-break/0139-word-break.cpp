class Solution {
private:
    bool solve(string s, set<string> &st, vector<int> &dp, int ind){
        
        if(ind == s.size() ) return 1;
        if(dp[ind] != -1) return dp[ind];
        
        string temp ="";
        for(int j = ind; j < s.size(); j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(solve(s, st, dp, j+1)) return dp[ind] = 1;
            }
        }
        return dp[ind] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> st(wordDict.begin(), wordDict.end());
        
        vector<int > dp(305, -1);
        solve(s, st, dp, 0);
        return dp[0]; 
    }
};