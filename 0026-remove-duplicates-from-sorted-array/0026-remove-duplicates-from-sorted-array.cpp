class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, i = 1;;
        int n = nums.size();
       for(; i < n; i++){
           if(nums[j] != nums[i])
            {
                nums[j+1] = nums[i];
                j++;
            }
        }
        return j+1;
    }
};