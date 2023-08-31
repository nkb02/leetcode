struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit] !=NULL;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int findMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i>= 0; i--){
            int bit = (num>>i) & 1;
            
            if(node->containsKey(1 - bit)){
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = nums.size();
        
        vector<int> ans(q, 0);
        vector<pair< int, pair<int, int> >> oQ;
        sort(nums.begin(), nums.end());
        int index = 0;
        
        // converting online Qs to offline Qs
        for(auto &it: queries){
            oQ.push_back({it[1], {it[0], index++}});
        }
        sort(oQ.begin(), oQ.end());
        index = 0;
        Trie trie;
        
        for(auto &it: oQ){
            while(index < n && nums[index] <= it.first){
                trie.insert(nums[index]);
                index++;
            }
            
            if(index != 0 ) ans[it.second.second] = trie.findMax(it.second.first);
            else ans[it.second.second] = -1;
        }
        
        
        return ans;
    }
};