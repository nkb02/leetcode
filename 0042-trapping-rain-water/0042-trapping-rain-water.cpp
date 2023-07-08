#define rep(i, m, n) for (int i = m; i < n; i++)
#define fl(i, n) for (int i = 0; i < n; i++)

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
         int maxL[n], maxR[n];
	    maxL[0] = a[0];
	    rep(i,1,n)
	    {
	        if(a[i]> maxL[i-1])
	            maxL[i] = a[i];
	        else
	            maxL[i] = maxL[i-1];
	    }
	    maxR[n-1] = a[n-1];
	    for (int i = n-2; i >= 0; i--)
	    {
	        if(a[i]> maxR[i+1])
	            maxR[i] = a[i];
	        else
	            maxR[i] = maxR[i+1];
	    }
	    int sum = 0;
	    fl(i,n)
	    {
	        sum += (min(maxR[i], maxL[i]) - a[i]);
	    }
	   return sum;
    }
};