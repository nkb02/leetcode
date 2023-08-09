//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool isprime(int n){
        if( n <= 1) return 0;
        for(int i = 2; i*i<= n; i++){
            if(n % i == 0) return false;
        }
        
        return true;
    }
    long long int largestPrimeFactor(int N){
        // code here
        if(isprime(N)) return N;
        int mx = -1;
        
        for(int i = 1; i*i <= N; i++){
            
            if(N % i == 0){
                int f1 = i;
                int f2 = N/i;
                
                if(isprime(f2)) return f2;
                if(isprime(f1)){
                    mx = f1;
                }
                
            }
        }
        return mx;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends