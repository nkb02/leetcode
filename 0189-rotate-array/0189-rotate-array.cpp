class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n==1) return;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin() +n- k, nums.begin() + n);
        reverse(nums.begin(), nums.begin() + n);
        
    }
};