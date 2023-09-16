class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        map<pair<int, int>, int> f;
        for(auto i: c) {
            f[{i[0], i[1]}]++;
        }
        long long ans = 0;
        for(auto i: c) {
            f[{i[0], i[1]}]--;
            for(int j = 0; j <= k; j++) {
                int x = j ^ i[0];
                int y = (k - j) ^ i[1];
                if(f.find({x, y}) != f.end()) {
                    ans += f[{x, y}];
                }
            }
            f[{i[0], i[1]}]++;
        }
        return ans / 2;
    }
};