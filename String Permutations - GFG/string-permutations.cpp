//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void permute(int ind, vector<string> &ans, string &src){
        if(ind == src.size()) {
            ans.push_back(src);
            return;
        }
        
        for(int i = ind; i < src.size(); i++){
            swap(src[i], src[ind]);
            permute(ind+1, ans, src);
            swap(src[i], src[ind]);
        }
        return;
    }
    vector<string> permutation(string S)
    {
        vector<string > ans;
        
        if(S.size() == 0) return ans;
        if(S.size() == 1) return {S}; 
        
        permute(0, ans, S);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends