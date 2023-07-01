class DisjointSet{
  public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUparent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0 ;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUparent(u) == ds.findUparent(v)){
                cntExtras++;
            }
            else
                ds.unionBySize(u,v);
        }
        
        int cntComponents = 0;
         for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntComponents++;
        }
        int ans = cntComponents - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};