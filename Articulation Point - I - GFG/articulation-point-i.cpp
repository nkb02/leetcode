//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    int timer = 0;
    void dfs(int node, int parent , vector<int> &vis ,
             vector<int> adj[], int tin[], int low[],
             vector<int> &mark)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++; 
        int child = 0; // for 1st node
        for(auto it : adj[node])
        {
            if(it == parent)continue;

            if(vis[it] == 0)
            {
                dfs(it, node, vis, adj, tin, low, mark);
                // if child has lower time to reach
                // take it in parent
                low[node] = min(low[node], low[it]);
                // check if node -- it is a bridge
                if(low[it] >=  tin[node] && parent!= -1)
                {
                    // it is an articulation point
                    mark[node] = 1;
                }
                child++;
            
            }
            else
            {
                // if child has lower time to reach
                // take it in parent
                low[node] = min(low[node], tin[it]);
                
            }
        }
    // for 1st node
        if(child > 1 && parent == -1)
        mark[node] = 1;
    }    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V, 0), mark(V,0);
        
        int tin[V]; // dfs time insertion
        int low[V]; // lowest time insertion of all adj node apart from  parent & visisted node
        
        for(int  i = 0; i < V ; i++)
        {
            if(!vis[i])
            {
                dfs(i, -1, vis, adj, tin, low, mark);
            }
        }
        vector<int> ans;
        for(int  i = 0; i < V ; i++)
        {
            if(mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0)
            return {-1};
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends