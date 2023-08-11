class Solution {
public:
    int change(int T, vector<int>& arr) {
        int n =arr.size();
        // vector<vector<long>> dp(n+1, vector<long>(T+1, 0));
        vector<long> prev(T+1, 0), cur(T+1, 0);
        // edge case
        
        for(int target = 0; target <= T; target++){
            if(target % arr[0] == 0) 
                prev[target] = 1;
        }
        for(int ind = 1; ind < n ; ind++){
           
            for(int target = 0; target <= T; target++){
                long notTake = prev[target];
                long take = 0;
                if(arr[ind] <= target){
                    take = cur[target-arr[ind]];
                }

                cur[target] = take + notTake;

            }
            prev = cur;
        }
        
        return  prev[T];
    }
    
};