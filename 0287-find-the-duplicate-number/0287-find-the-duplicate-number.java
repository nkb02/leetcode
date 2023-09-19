class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[n+1];
        
        for(int i = 0; i < n; i++){
            if(cnt[nums[i]] == 0) cnt[nums[i]]++;
            else return nums[i];
        }
        return -1;
    }
}