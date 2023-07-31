class Solution {
private:
    // memoized
    int lcs(string &s1, string &s2, int n, int m, int i, int j,
            vector<vector<int>> &dp){
        if(i<= 0 && j <=0)
        {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = lcs(s1, s2, n, m, i-1, j-1, dp) ;
        } else {
            dp[i][j] = min(lcs(s1, s2, n, m, i-1, j, dp)  + s1[i - 1], 
                           lcs(s1, s2, n, m, i, j-1, dp)  + s2[j - 1]);
        }
        return dp[i][j];
    }
public:
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+5, vector<int> (m+5, -1));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        
        for (int j = 1; j <= m; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        
        int dummy = lcs(s1, s2, n, m, n, m, dp);
        return dp[n][m];
    }
};