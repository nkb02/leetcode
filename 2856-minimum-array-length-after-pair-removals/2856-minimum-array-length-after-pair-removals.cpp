
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = (n+1)/2;
        int used = 0;
        
        while(j < n) {
            if(nums[i] < nums[j]) {
                i++;
                used++;
            }

            j++;
        }
        
        return n - 2*used;
    }
};