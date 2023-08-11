//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int target) {

        // unbounded knapsack
        // vector<vector<long long int> > dp(N+1, vector<long long int> (target +1, 0));
        
        // space optimation
        vector<long long int> prev(target+1, 0), cur(target+1, 0);
        // edge case
        for(int sum = 0 ; sum <= target; sum++){
            if(sum % coins[0] == 0) prev[sum] = 1;
        }
        for(int ind = 1; ind < N; ind++){
             for(int sum = 0 ; sum <= target; sum++){
                long long take = 0, notTake;
                if(coins[ind] <= sum){
                    take = cur[sum - coins[ind]];
                }
                // not take
               
                notTake = prev[sum];
                
                cur[sum] = notTake + take;     
            }
            prev = cur;
        }
        return prev[target];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends