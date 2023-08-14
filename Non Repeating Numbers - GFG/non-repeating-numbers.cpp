//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xx = 0;
        for(auto x: nums) xx = xx ^ x;
        
        int cnt = 0; // rightmost set bit -- LSB
        while(xx){
            if(xx & 1) break;
            cnt++;
            xx = xx >> 1;
        }
        int x1 = 0, x2 = 0;
        for(auto it: nums){
            if(it & (1<< cnt)) x1 = x1 ^ it;
            else x2 = x2 ^ it;
        }
        if(x1 > x2) swap(x1, x2);
        return {x1, x2};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends