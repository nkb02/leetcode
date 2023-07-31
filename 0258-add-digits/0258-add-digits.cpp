class Solution {
private:
    int solve(string s){
        int n = s.size();
        int sum = 0;
        for(auto x: s){
            sum += x-'0';
        }
        return sum;
    }
public:
    int addDigits(int num) {
        int ans  =0 ;
        string s = to_string(num);
        if(s.size() == 1) return num;
        while(s.size() != 1)
        {
            ans = solve(s);
            s = to_string(ans);
        }
        return ans;
    }
};