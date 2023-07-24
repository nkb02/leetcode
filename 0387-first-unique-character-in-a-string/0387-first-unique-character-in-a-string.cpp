class Solution {
public:
    int firstUniqChar(string s) {
        // freq, char, ind
        vector<pair<int, int>> hash(26,pair<int,int>({0,0}));
        for(int i = 0; i <s.size(); i++){
            hash[s[i]-'a'].first++;
            hash[s[i]-'a'].second = i;
        }
        sort(hash.begin(), hash.end());
        int i = 0;
        while(i< 26 && hash[i].first != 1) i++;
        if(i <26)
            return hash[i].second;
        return -1;
    }
};