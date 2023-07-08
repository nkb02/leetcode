class Solution {
private:
    vector<int> nextLargerElement(vector<int> arr, int n){
	    vector<int> nge(n);
	    stack<int> s;
	    for(int i = n-1 ; i >= 0; i--)
	    {
	        if(s.size() == 0 )
	        {
	            nge[i]= -1;
	        }
	        else if(s.size() > 0 && s.top() > arr[i]){
	            nge[i] = s.top();
	        }
	        else if(s.size() > 0 && s.top() <= arr[i]){
	            while(s.size() > 0 && s.top() <= arr[i])
	                {
	                    s.pop();
	                }
	            if(s.size() == 0)
	            {
	                nge[i]= -1;
	            }
	            else
	            {
	                nge[i] = s.top();
	            }
	        }
	        s.push(arr[i]);
	    }
	    return nge;
	    
	}
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge = nextLargerElement(nums2, nums2.size());
        
        int k =nums1.size();
        map<int, int> hash;
        for(int i = 0; i < nums2.size(); i++){
            hash[nums2[i]] = i; 
        }
    
        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(nge[hash[x]]);
        }
        return ans;
    }
};