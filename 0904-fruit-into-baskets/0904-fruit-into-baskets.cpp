class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i =0, j=0 , n = fruits.size();
        int k = 2;
        int mx =0;
        if(n == 1) return 1;
        while(j < n){
            mp[fruits[j]]++;
            if(mp.size() < k)
                j++;
            else if(mp.size() == k){
                mx = max(mx, j - i + 1);
                j++;
            }
            else{
                while(mp.size() > k){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return mx == 0 ? mp[fruits[0]] : mx;
    }
};