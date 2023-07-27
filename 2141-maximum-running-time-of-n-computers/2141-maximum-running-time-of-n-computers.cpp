class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        int size = batteries.size();
        for(int i = 0; i <size; i++){
            sum += batteries[i];
        }
        
        sort(batteries.begin(), batteries.end());
        long long lo = batteries[size-n];
        long long hi = sum / n;
        
        long long ans = 0;
        
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            int k =size-1;
            while(k >= 0 && batteries[k] > mid){
                k--;
            }
            int rem = n - (size-1 -k );
            long long temp = 0;
            while(k >= 0)
                temp += batteries[k], k--;
            
            if(rem <= 0 || rem * mid <= temp)
                lo = mid +1;
            else
                hi = mid -1;
        }
        return hi;
    }
};