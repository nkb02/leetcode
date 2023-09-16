class Solution {
public:
  
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int mini = 200;
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                pos = i;
            }
        }
        vector<int> temp = nums;
        int  x = pos;
        int cnt = 1, i = 0;
        while(cnt < n){
            if(nums[(x+i)%n] > nums[(x+i+1) % n]) return -1;
            i++;
            cnt++;
        }
        // sort(temp.begin(), temp.end());
        // for(int i = 0; i < n;i ++){
        //     if(temp[i] != nums[(x + i) % n])
        //         return -1;
        // }
        if(pos == 0)
            return pos;
        else
            return n - pos;
  

    }
};