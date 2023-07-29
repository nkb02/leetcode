class Solution {
private:
    bool check(int cnt1[26], int cnt2[26]){
        for(int i = 0 ;i < 26; i++){
            if(cnt1[i] != cnt2[i]) return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int cnt1[26] = {0};
        
        for(auto ch : s1){
            cnt1[ch-'a']++;
        }
        
        // window size = s1.size
        // checking for first window
        int n1=  s1.size();
        int n2 =  s2.size();
        int cnt2[26] = {0};
        int i = 0;
        
        while(i < n1 && i < n2){
            cnt2[s2[i]-'a']++;
            i++;
        }
        if(check(cnt1, cnt2)) return 1;
        
        while(i < n2){
            cnt2[s2[i]-'a']++;
            cnt2[s2[i-n1]-'a']--;
            if(check(cnt1, cnt2)) return 1;
            
            i++;
        
        }
        return 0;
    }
};