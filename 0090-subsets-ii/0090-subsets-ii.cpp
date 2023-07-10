class Solution {
public:
    void subsets(int ind, vector<int> &A, vector<int> &ds, vector<vector<int> >&ans){
        ans.push_back(ds);
        
        for(int i = ind; i < A.size(); i++){
            // ignoring duplicates
            if(i != ind && A[i] == A[i-1]) continue;
            
            ds.push_back(A[i]);
            subsets(i+1, A, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& A) {
        vector<vector<int> >ans;
        vector<int> ds;
        
        sort(A.begin(), A.end());
        subsets(0, A, ds, ans);
        return ans;        
    }
};