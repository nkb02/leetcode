class Solution {
public:
    int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze,vector<vector<int>> &dp) 
    {
        for(int i=0; i<n ;i++){
          for(int j=0; j<m; j++){
               if(i==0 && j==0){
                  dp[i][j]=1;
                  continue;
              }
              //base conditions
              if(i>0 && j>0 && maze[i][j]== 1){
                dp[i][j]=0;
                continue;
              }


              int up=0;
              int left = 0;

              if(i>0 && maze[i-1][j] != 1) 
                up = dp[i-1][j];
              if(j>0 && maze[i][j-1] != 1)
                left = dp[i][j-1];

              dp[i][j] = up+left;
          }
      }

      return dp[n-1][m-1];


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        // corner cases
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return mazeObstaclesUtil(n,m,obstacleGrid,dp);
    }
};