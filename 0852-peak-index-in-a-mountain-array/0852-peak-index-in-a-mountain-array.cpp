class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int mx = 0;
        int n = arr.size();
        for(int i =1; i <n ; i++){
            if(arr[i] > arr[mx]){
                mx = i;
            }
            else break;
        }
        return mx;
        
    }
};