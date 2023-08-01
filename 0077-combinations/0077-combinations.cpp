class Solution {
private:
    void fun(int n ,int k,  vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(n== 0) return;
        
        // take 
        ds.push_back(n);
        fun(n-1, k, ans, ds);
        ds.pop_back();
        
        // not take
        fun(n-1, k, ans, ds);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        if(n == 1) return {{1}};
        
        fun(n, k, ans, ds);
        return ans;
        
    }
};