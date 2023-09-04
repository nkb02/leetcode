//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // boundary O's bfs
        
        vector<vector<int> > vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i= 0; i< n; i++){
            if(mat[i][0] == 'O') q.push({i, 0});
            if(mat[i][m-1] == 'O') q.push({i, m-1});
            
        }
        for(int j= 0; j< m; j++){
            if(mat[0][j] == 'O') q.push({ 0, j });
            if(mat[n-1][j] == 'O') q.push ({ n-1, j });
        }
        
        int drow[] = {0, 0, 1, -1 } ;
        int dcol[] = {1, -1, 0, 0 } ;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            
            
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] 
                    && mat[nrow][ncol] == 'O'){
                        q.push({nrow, ncol});
                    }
            }    
        }
        
        
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends