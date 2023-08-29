class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> dp(n+1, 0);
        for(auto it : customers) if(it == 'N') dp[n]++;
        for(int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1] + (customers[i] == 'Y') - (customers[i] == 'N');
        }
        
        int pos = -1;
        int mini = INT_MAX;
        
        for(int i = 0; i<= n; i++){
            if(dp[i] < mini){
                mini = dp[i];
                pos = i;
            }
        }
        return pos;
    }
};