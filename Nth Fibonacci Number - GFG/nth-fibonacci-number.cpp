//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9 + 7;
    int nthFibonacci(int n){
        long long prev1 = 0;
        long long prev2 = 1;
        long long cur = 0;
        for(int i = 2; i<= n; i++){
            cur = (prev1 + prev2) % mod;
            
            prev1 = prev2;
            prev2 = cur;
        }
       return cur % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends