class Solution {
private:
    int f(int ind, vector<int> &num, int k, int n, vector<int> &dp){
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
          for (int j = ind; j < min(ind + k, n); j++) {
                len++;
                maxi = max(maxi, num[j]);
                int sum = len*maxi + f(j+1, num, k, n, dp);
              maxAns = max(maxAns, sum);
          }
        return dp[ind] = maxAns;
        
    }
public:
    int maxSumAfterPartitioning(vector<int>& num, int k) {
        int n =num.size();
        vector<int> dp(n+1, 0);
        for(int ind = n-1; ind>= 0; ind--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;

              for (int j = ind; j < min(ind + k, n); j++) {
                    len++;
                    maxi = max(maxi, num[j]);
                    int sum = len*maxi + dp[j+1];
                    maxAns = max(maxAns, sum);
              }
             dp[ind] = maxAns;
        }
        return dp[0];
    }
};