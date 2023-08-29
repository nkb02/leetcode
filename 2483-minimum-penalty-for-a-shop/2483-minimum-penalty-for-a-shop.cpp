class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> dp(n+1, 0);
        for(auto it : customers) if(it == 'N') dp[n]++;
        
        int pos = n;
        int mini = dp[n];
 
        for(int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1] + (customers[i] == 'Y') - (customers[i] == 'N');
             if(dp[i] <= mini){
                mini = dp[i];
                pos = i;
            }
        }
        
       
        return pos;
    }
};