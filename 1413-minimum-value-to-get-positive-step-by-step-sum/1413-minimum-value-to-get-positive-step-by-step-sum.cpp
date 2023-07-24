class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn = INT_MAX;
        int sum = 0;
        bool neg =false;
        for(auto x: nums){
            sum += x;
            if(x < 0) neg = true;
            mn = min(mn, sum);
        }
        if(mn >= 1) return 1;
        
        return abs(mn) + 1;
        
    }
};