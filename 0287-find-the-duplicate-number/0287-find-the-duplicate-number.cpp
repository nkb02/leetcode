class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
       vector<int> cnt(n+1, 0);
        for(int i = 0; i< n;i++){
           if(cnt[nums[i]] == 0) cnt[nums[i]]++;
            else return nums[i];
        }
        return -1;
    }
};