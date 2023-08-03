class Solution {
private:
    void solve(string &digits, string &s, vector<string> &ans, map<int, string> &mp, int ind){
        if(digits.size() == s.size()){
            ans.push_back(s);
            return;
        }
        string t = mp[digits[ind]-'0'];
        for(int i = 0; i < t.size(); i++){
            s.push_back(t[i]);
            solve(digits, s, ans, mp, ind+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        
        vector<string> ans;
        if(digits.size() == 0) return ans;
        
        string s = "";
        solve(digits, s, ans, mp, 0);
        
        return ans;
    }
};