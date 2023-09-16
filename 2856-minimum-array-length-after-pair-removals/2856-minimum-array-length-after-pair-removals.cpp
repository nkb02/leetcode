
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int > left, right;
        for (int i = 0; i < (n+1)/2; ++i)
        {
            left.push_back(nums[i]);
        }

        for (int i = (n+1)/2; i < n; ++i)
        {
            right.push_back(nums[i]);
        }

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        
        // for(auto x: left) cout<< x<<" ";
        //     cout<<endl;
        // for(auto x: right) cout<< x<<" ";
        //     cout<<endl;
        
        int ans = n;
        int  i=0, j = 0;
        int lsize = left.size();
        int rsize = right.size();
        while(i < lsize && j < rsize){
            if(left[i] < right[j]){
                i++;
                j++;
                ans-=2;
            }
            else{
                j++;
            }
            
        }
        return ans;
    }
};