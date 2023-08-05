//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        if( m == 1) return 0;
        sort(a.begin(), a.end());
        
        long long ans = -1;
        long long mn = LONG_MAX;
        
        long long i = 0;
        long long j = m-1;
        long long size = a.size();
        
        while(j < size){
            long long maxi = a[j];
            long long mini = a[i];
            mn = min ( mn, maxi - mini);
            i++;
            j++;
        }
        
        return mn;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends