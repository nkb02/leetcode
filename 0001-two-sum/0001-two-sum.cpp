class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         
        int n = nums.size();
        int j = n-1;
        int i = 0;
        unordered_map<int, int> mpp;
        for(int i = 0 ; i < n; i++)
        {
            int cur = nums[i];
            if(mpp.find(target - cur) != mpp.end())
            {
                return {i, mpp[target - cur]};
            }
                mpp[cur] = i;
        }

        return {-1};
    }
};