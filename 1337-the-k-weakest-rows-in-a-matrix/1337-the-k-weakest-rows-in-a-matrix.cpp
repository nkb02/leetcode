class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<pair<int, int>> cnt;
        for(int i = 0; i<n; i++){
            cnt.push_back({i, 0});
            for(int j = 0; j< m; j++){
                if(mat[i][j] == 1)
                    cnt[i].second++;
                else
                    break;
            }
        }
        sort(cnt.begin(), cnt.end(), comp);
        vector<int> ans;
        for(int i = 0; i< k; i++)
            ans.push_back(cnt[i].first);
        
        return ans;
    }
    static bool comp(pair<int, int>&a, pair<int, int> &b){
        if(a.second == b.second){
            return a.first< b.first;
        }
        return a.second < b.second;
    }
};