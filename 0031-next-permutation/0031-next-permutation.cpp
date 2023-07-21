class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        
        int ind = -1;
        // find break point
        for(int i = n-2 ; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) {
            // i.e. it is last permutation
            reverse(nums.begin(), nums.end());
            // return nums;
            return;
        }
        
        // find next greater elem from back of nums[ind]
        for(int i = n-1; i >=0 ; i--){
            if(nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ ind+1, nums.end());
        // return nums;
        return;
    }
};