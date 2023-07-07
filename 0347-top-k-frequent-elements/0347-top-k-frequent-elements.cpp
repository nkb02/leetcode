class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto x: nums) mp[x]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        for(auto it: mp){
            minh.push({it.second, it.first});
            
            if(minh.size() > k) minh.pop();
        }
        
        vector<int> ans(k);
        int a = 0;
        while(!minh.empty()){
            ans[a++] = minh.top().second;
            minh.pop();
        }
        
        return ans;
    }
};