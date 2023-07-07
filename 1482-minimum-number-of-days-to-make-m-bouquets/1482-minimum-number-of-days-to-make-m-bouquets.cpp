class Solution {
    bool ispossible(vector<int>& a, int m, int k, int day){
        int n = a.size(); //size of the array
        int cnt = 0;
        int noOfB = 0;
        
         for (int i = 0; i < n; i++) {
            if (a[i] <= day) {
                cnt++;
            }
            else {
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1; // impossible case
        
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int mid ;
        
        int ans = 0;
        int cnt = 0;
        while(start <= end){
            mid = (start+end)/2;
            
            if(ispossible(bloomDay, m, k, mid) ){
                end = mid- 1;
            }
            else
                start = mid+1;
        }
        return start;
    }
};