class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> st(wordDict.begin(), wordDict.end());
        
        vector<int > dp(305, 0);
        int n = s.size();
        dp[n] =1;
        for(int ind = n-1; ind>= 0; ind--){

            string temp ="";
            for(int j = ind; j < n; j++){
                temp += s[j];
                if(st.find(temp) != st.end() && dp[j+1] == 1){
                 dp[ind] = 1;
                }
            } 

        }
        return dp[0]; 
    }
};