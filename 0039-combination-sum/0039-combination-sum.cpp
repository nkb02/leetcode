class Solution {
public:
void printSubs(vector<int> &arr, int n, int index, vector<int>&ds, int target, vector<vector<int> > &ans){
    if(index == n){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    // pick
    if(arr[index] <= target){
        ds.push_back(arr[index]);
        
        printSubs(arr, n, index, ds, target-arr[index], ans);
        ds.pop_back();
        
    }

    printSubs(arr, n, index+1, ds, target, ans);
    return;
    // not pick
}
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        int n = A.size();
        sort(A.begin(), A.end());
        
        int index = 0;
        vector<vector<int> > ans;
        vector<int> ds;
        
        printSubs(A, n, index, ds, B, ans);
        // set<vector<int>> st (ans.begin(), ans.end());
        // ans.clear();
        // for(auto it: st){
        //     ans.push_back(it);
        // }
        return ans;
    }
};