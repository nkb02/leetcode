class Solution {
public:
    int change(int T, vector<int>& arr) {
        int n =arr.size();
        vector<vector<long>> dp(n+1, vector<long>(T+1, -1));
        
        return solve(arr, n-1, T, dp );
    }
    
    long solve(vector<int> &arr, int ind, int target, vector<vector<long>> &dp){
        if(ind == 0){
            return (target % arr[ind] == 0);
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        long notTake = solve(arr, ind-1, target, dp);
        
        long take = 0;
        if(arr[ind] <= target){
            take = solve(arr, ind, target-arr[ind], dp);
        }
        
        return dp[ind][target] = take + notTake;
    }
};