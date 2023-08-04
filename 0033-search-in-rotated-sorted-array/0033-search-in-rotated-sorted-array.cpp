class Solution {
    
    int bsInRotatedArray(int lo, int hi, int target, vector<int>& nums){
     int mid;
    while(lo <= hi){
        mid = lo + (hi-lo)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[mid] > target)
        {
            hi = mid-1;
        }
        else 
        {
            lo = mid+1;
        }    
    }
    return -1;
} 
public:
    int search(vector<int>& nums, int target) {
        int index = 0;
        int n =nums.size();
        int prev = -1, next = -1;
        
        int lo = 0;
        int hi = n-1;
        int mid;
        // finding the index of min element in logN
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            next = (mid+1)%n;
            prev = (mid+n -1)% n;
            // cout<<prev<<" "<<mid<<" "<<next<<"\n";
            if(nums[mid] < nums[prev]){
                index = mid;
                break;
            }
            if(nums[mid] >= nums[0])
            {
                lo = mid+1;
            }
            else 
            {
                hi = mid-1;
            }    
        }
        int ans1 = bsInRotatedArray(0, index-1, target, nums);
        int ans2 = bsInRotatedArray(index, n-1, target,nums);
        if(ans1 == -1 && ans2 == -1)
        {
            return -1;
        }
        if(ans1 >= 0)
            return ans1;
        else
            return ans2;
        }
};