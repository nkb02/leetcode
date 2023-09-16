class Solution {
public:
    int dfs(int u,int par,vector<vector<pair<int,int>>>& adj,vector<int>& ans,vector<int>& cnt){
        int c1=0;
        for(auto p:adj[u]){
            if(p.first==par) continue;
            if(p.second==1) c1++;
            c1+=dfs(p.first,u,adj,ans,cnt);
        }
        cnt[u]=c1;
        ans[u]+=c1;
        return c1;
    }
    
    void dfs2(int u,int par,vector<vector<pair<int,int>>>& adj,vector<int>& ans,vector<int>& cnt,vector<int>& cnt2){
        for(auto p:adj[u]){
            if(p.first==par) continue;
            int x=cnt[u]+cnt2[u];
            if(p.second==1) x--;
            else x++;
            x=x-cnt[p.first];
            cnt2[p.first]=x;
            ans[p.first]+=x;
            dfs2(p.first,u,adj,ans,cnt,cnt2);
        }
    }
    
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto v:edges){
            adj[v[0]].push_back({v[1],0}); // for given edge put weight = 0
            adj[v[1]].push_back({v[0],1}); // add reverse edge put weight = 1
        }
        vector<int> ans(n,0);
        vector<int> cnt(n,0),cnt2(n,0);
        dfs(0,-1,adj,ans,cnt);
        dfs2(0,-1,adj,ans,cnt,cnt2);
        return ans;
    }
};