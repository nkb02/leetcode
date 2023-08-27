class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int target = stones[n-1];
        vector<vector<int>> dp(2005, vector<int>(2005, -1)); 
        return solve(stones, 0, 0, dp);
    }
    bool solve(vector<int>& stones, int last, int index, vector<vector<int>> &dp){
        if(index == stones.size() - 1 ) return true;
        if(index >= stones.size()) return false;
        if(dp[index][last] != -1) return dp[index][last];
        
        bool res= false;
        for(int j = -1; j <= 1; j++){
            int nextJump = j + last;
            if(nextJump > 0){
                int ind = lower_bound(stones.begin(), stones.end(), stones[index] + nextJump)- stones.begin();
                if(ind == stones.size() || stones[ind] != stones[index] + nextJump)
                    continue ; // not found
                
                res = res || solve(stones, nextJump, ind, dp);
            }
        }
        return dp[index][last] = res;
        
    }
    
//     int find(int target, vector<int> & stones){
//         int lo = 0;
//         int hi = stones.size() -1;
//         int mid;
        
//         while(lo<= hi){
//             mid = (lo+hi)/2;
//             if(stones[mid] == target) return mid;
//             else if(stones[mid] < target){
//                 lo = mid +1;
//             } 
//             else hi= mid -1;
//         }
//         return stones.size();
//     }
    
};