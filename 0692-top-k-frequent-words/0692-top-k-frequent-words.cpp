 class cmp{  //  a comparator class
        public:
        bool operator()( pair<int,string> &p1,const pair<int,string> &p2)
        {
            if(p1.first==p2.first) return p1.second>p2.second; // smaller string at top
            
               return p1.first<p2.first;  // larger string at top// larger freq at top
        }
        
    };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> minh;
        
        unordered_map<string, int> mp;
        for(auto it: words){
            mp[it]++;
        }
        for(auto it: mp){
            minh.push({it.second, it.first });
        }
        
        vector<string> ans;
        while(k-- && !minh.empty()){
            auto it = minh.top();
            ans.push_back(it.second);
            minh.pop();
        }
        return ans;
    }
};