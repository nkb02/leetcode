class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int r = 0;
        int c = col-1;
        while(r >= 0 && r < row && c>= 0 && c < col){
            int t = matrix[r][c];
            if(t == target)
                return true;
            else if( t > target){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};