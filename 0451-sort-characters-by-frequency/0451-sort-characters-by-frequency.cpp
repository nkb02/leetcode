class Solution {
public:
    string frequencySort(string s) {
        priority_queue < pair < int,char >> maxh;
        unordered_map<char, int> mp;
        for(auto xx: s) mp[xx]++;

        for(auto xx : mp){
            maxh.push({xx.second, xx.first});
        }

        string ans = "";
        while(!maxh.empty()){
            auto xx = maxh.top();
            int time = xx.first;
            char ch = xx.second;
            for(int i = 0 ; i < time ; i++)
                ans.push_back(ch);

            maxh.pop();
        }

        return ans;
    }
};