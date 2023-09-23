//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n== 1) return 1;
        vector < long long >prefix(n+1, 0), suffix(n+1, 0);
        
        for(int i = 0; i< n; i++)
        {
            prefix[i+1] = prefix[i] + a[i];
        }
        suffix[n] = a[n-1];
        for(int i = n-1; i > 0; i--)
        {
            suffix[i] = suffix[i+1] + a[i-1];
        }
        
        // for(int i = 0; i<= n; i++) cout<< prefix[i] <<" ";
        // cout<<endl;
        // for(int i = 0; i<= n; i++) cout<< suffix[i] <<" ";
        // cout<<endl;
        
        for(int i = 1; i< n; i++) 
        {
            if(prefix[i-1] == suffix[i+1])
                return i;
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends