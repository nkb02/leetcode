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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, -1);
        return f(0, arr, k, arr.size(), dp);
    }
};