//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] != 1) return -1;
        if(A[X][Y] != 1) return -1;
        if(X == 0 && Y == 0) return 0;
        
        
        
        queue<pair<int, pair< int, int >>> q;
        vector<vector<int>> dist(N+1, vector<int> (M+1, 1e9));
        
        q.push({0, {0,0}});
        dist[0][0] = 0;
        
        int drow[] = {0 ,1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int x  = it.second.first;
            int y  = it.second.second;
            int dis = it.first;
            
            for(int i =0 ; i< 4 ; i++){
                int nx = x + drow[i];
                int ny = y + dcol[i];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] == 1
                && dis + 1 < dist[nx][ny] ){
                    dist[nx][ny] = dis + 1 ;
                     if(nx == X &&  ny== Y){
                        return dist[nx][ny];
                    }
                    q.push({1 + dis, {nx, ny}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends