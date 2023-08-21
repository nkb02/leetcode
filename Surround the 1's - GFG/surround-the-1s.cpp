//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
              
                if(matrix[i][j] == 1){
                    int one = 0;
                    for(int x = -1; x<= 1; x++){
                        for(int y = -1; y<= 1; y++){
                            int nrow = i + x;
                            int ncol = j + y;
                            
                            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && matrix[nrow][ncol] == 0){
                                one++;
                            }    
                        }
                        
                    }
                    if(one != 0 && one % 2 == 0) cnt++;
                }
                
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends