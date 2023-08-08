class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int i = n -1;
        int carry = 1;
        vector<int> ans;
        while(i >= 0 || carry> 0){
            int d = 0;
            if(i>= 0) d = digits[i];
            d += carry;
            carry = d / 10;
            d = d %10;
            ans.push_back(d);
            i--;
        }
        if(carry != 0) ans.push_back(carry); 
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};