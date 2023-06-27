class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
          int n = nums.size();
          int cnt = 1;
          vector<int> temp;
          temp.push_back(nums[0]);

          for(int i = 1; i < n ; i++){
              if(temp.back() < nums[i]){
                  temp.push_back(nums[i]);
                  cnt++;
              }
              else{
                  int ind = lower_bound(temp.begin(), temp.end(), nums[i]) 
                            - temp.begin();
                  temp[ind] = nums[i];
              }
                  
      
          }
          return cnt;
    }
};