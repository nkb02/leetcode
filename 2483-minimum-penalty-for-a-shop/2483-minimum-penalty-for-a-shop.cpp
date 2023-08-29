class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        // vector<int> dp(n+1, 0);
        int next = 0;
        int cur = 0;
        for(auto it : customers) if(it == 'N') next++;  //dp[n]++;
        
        int pos = n;
        int mini = next; //dp[n];
 
        for(int i = n-1; i >= 0; i--){
            cur = next + (customers[i] == 'Y') - (customers[i] == 'N');
             if(cur <= mini){
                mini = cur;
                pos = i;
            }
            next = cur;
        }
        
       
        return pos;
    }
};