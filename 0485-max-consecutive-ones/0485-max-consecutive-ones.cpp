class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cnt = 0;
        for(auto x: nums){
            if(x == 1)
            {
                cnt++;
            }
            else 
                cnt = 0;

            mx = max(mx, cnt);
        }
        return mx;
    }
};