class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using min heap
        // tc - O(klog k)
        priority_queue<int, vector<int>, greater<int>> minh;
        for(auto x : nums){
            minh.push(x);
            if(minh.size() > k)
                minh.pop();
        }
        return minh.top();
    }
};