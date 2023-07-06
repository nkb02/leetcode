//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int i = 0 ;
        long long int j = x ;
        while (i<= j ){
            long long int mid = (i+j)/2;
            long long int num = mid*mid;
            if(num == x){
                return mid;
            }
            if(num < x) i = mid +1;
            else j = mid-1;
        }
        return j;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends