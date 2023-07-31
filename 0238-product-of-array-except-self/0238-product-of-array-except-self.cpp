class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+2, 1);
        vector<int> suffix(n+2, 1);
        
        for(int i = 1; i <= n ; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i = n; i > 0 ; i--){
            suffix[i] = suffix[i+1] * nums[i-1];
        }
        // for(int i = 0; i <= n ; i++){
        //     cout<< prefix[i] <<" " ;
        // }
        // cout<<endl;
        // for(int i = 0; i <= n+1 ; i++){
        //     // cout<< suffix[i] <<" " ;
        // }
        // cout<<endl;
        vector<int> ans(n);
        for(int i = 0 ; i <n ; i++){
            ans[i] = prefix[i] * suffix[i+2];
        }
        return ans;
        
    }
};