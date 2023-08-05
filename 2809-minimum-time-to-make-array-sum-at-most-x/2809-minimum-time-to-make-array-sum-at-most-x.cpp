class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size(); 
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end());
        vector<int> dp(n+1, 0);
        for (int j = 0; j < n; j++)
            for (int i = n-1; i >= 0; i--) 
                dp[i+1] = max(dp[i+1], dp[i] + v[j].first * (i+1) + v[j].second);
        int n1 = accumulate(nums1.begin(), nums1.end(), 0);
        int n2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i <= n; i++) 
            if (n2 * i + n1 - dp[i] <= x) 
                return i;
        return -1;        
    }
};

