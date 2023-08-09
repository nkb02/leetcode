class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long n = candies.size();
        long long lo = 0;
        long long hi = 1e9;
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(k > sum) return 0;
        if(k == sum) return 1;
        
        while(lo <= hi){
            long long mid = lo+ (hi-lo)/2;
            long long kids = 0;
            if(mid == 0) {
                lo = mid +1;
                continue;
            }
            for(auto &it : candies)
                kids+= it/mid;
            
           if(k > kids){
                hi = mid-1;
            }
            else
                lo = mid+1;
            
        }
        return (int)hi;
    }
};