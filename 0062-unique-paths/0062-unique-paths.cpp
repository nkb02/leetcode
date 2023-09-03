class Solution {
public:
    int paths( int m, int n ){
        vector<int> prev(n, 0), cur(n, 0);
        for(int i = 0 ; i< m; i++){
            for(int j = 0; j < n; j++){
                if(i==0 && j ==0){
                    cur[j] = 1;
                    continue;
                }
                int up = 0;
                int left= 0;
                if(i> 0){
                   up = prev[j];
                }
                if(j> 0){
                   left = cur[j-1];     
                }
                cur[j] = up+left;
            }
            prev = cur;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        return paths(m,n);
    }
};