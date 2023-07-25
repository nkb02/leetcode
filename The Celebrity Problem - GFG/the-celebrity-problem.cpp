//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool check(vector<vector<int> >& M, int n, int p1 , int p2){
        return M[p1][p2] == 1;
     }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0 ; i< n; i++)
            st.push(i);
            
        while(st.size() > 1){
            int p1 =st.top();
            st.pop();
            int p2 =st.top();
            st.pop();
            
            if(check(M, n, p1, p2)){
                st.push(p2);
            }
            else
                st.push(p1);
        }
        
        int ans = st.top();
        int cntzero = 0, cntOne = 0;
        for(int i = 0 ; i< n; i++){
            if(M[i][ans] == 1) cntOne++;
        }
        if(cntOne != n-1) return -1;
        
        cntzero = 0;
        for(int i = 0 ; i< n; i++){
            if(M[ans][i] == 0) cntzero++;
        }
         if(cntzero != n) return -1;
         
         return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends