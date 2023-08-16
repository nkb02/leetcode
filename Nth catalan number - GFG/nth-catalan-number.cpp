//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    int MOD = 1000000007;
    int MAX_N = 1000;
    
public:
    
    
    std::vector<int> factorialCache;
    
    void precomputeFactorials() {
        for (int i = 2; i <= MAX_N * 2; ++i) {
            factorialCache[i] = (factorialCache[i - 1] * 1LL * i) % MOD;
        }
    }
    
    int modInverse(int a, int m) {
        int m0 = m;
        int y = 0, x = 1;
    
        if (m == 1) {
            return 0;
        }
    
        while (a > 1) {
            int q = a / m;
            int t = m;
            m = a % m, a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
    
        if (x < 0) {
            x += m0;
        }
    
        return x;
    }
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        factorialCache.resize(2*MAX_N +1 , 1);
        precomputeFactorials();
        int numerator = factorialCache[2 * n];
        int denominator = (factorialCache[n + 1] * 1LL * factorialCache[n]) % MOD;
        
        int modInverseDenominator = modInverse(denominator, MOD);
        
        return (numerator * 1LL * modInverseDenominator) % MOD;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends