class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        
        int lo = 1;
        int hi = 1e9;
        
        while(lo<= hi){
            int mid = (lo+hi)/2;
            int take = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    take += 1;
                    // to avoid adj house
                    i++;
                }
            }
            // cout<<take<<" ";
            if(take >= k) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};