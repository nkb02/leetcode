class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_map<string, int> mp;
        for(auto word: dictionary) mp[word]++;
        
        vector<int> dp(n+1, 0);
        
        for(int ind = n-1; ind>= 0; ind--){
            string cur = "";
            int minExtra = s.size();
            for(int cutInd = ind; cutInd < n ; cutInd++){
                cur.push_back(s[cutInd]);
                
                int curExtra = mp.count(cur)? 0: cur.size();
                int nextExtra = dp[cutInd + 1];
                int totalExtra = curExtra + nextExtra;
                
                minExtra = min(minExtra, totalExtra);
            }
            dp[ind] = minExtra;
        }
        
        return dp[0];
    }
};