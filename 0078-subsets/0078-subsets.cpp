class Solution {
public:
    // using recursion 
    void generateSubsets(vector<int> &nums, vector<int> &ds, vector<vector<int>>&ans, int index, int size){
        if(index == size){
            ans.push_back(ds);
            return;
        }
        // take
        ds.push_back(nums[index]);
        generateSubsets(nums, ds, ans, index+1, size);
        ds.pop_back();
        // not take
        generateSubsets(nums, ds, ans, index+1, size);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>> ans;
        if(n == 0) return ans;
         vector<int> ds;
         generateSubsets(nums, ds, ans, 0, n);
         
         return ans;
    }
};