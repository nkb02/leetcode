class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int lo = 0;
        int hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi) /2;
            if(nums[mid] == target) return 1;
            // for duplicates 
            //Edge case:
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo = lo + 1;
                hi = hi - 1;
                continue;
            }
            // if left part is sorted
            if(nums[lo] <= nums[mid]){
                if(nums[lo] <= target && target <= nums[mid])
                {
                    // elem exist
                    hi = mid -1;
                }
                else
                    lo = mid+1; // elem dne
            }
            // if right part is sorted
            else{
                if(nums[mid] <= target && target <= nums[hi])
                {
                    // elem exist
                    lo = mid +1;
                }
                else
                    hi = mid -1; // elem dne
            }
            
        }
        
        return false;
    }
};