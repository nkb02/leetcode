//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> ans;
        sort(arr, arr+n);
        
        for(int i = 0; i < n-1 ; i++){
            if(arr[i] == arr[i+1])
            {
                if(ans.empty() || ans.back() != arr[i])
                    ans.push_back(arr[i]);
            }
        }
        if(ans.size() == 0) return {-1};
        // sort(begin(ans), end(ans));
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends