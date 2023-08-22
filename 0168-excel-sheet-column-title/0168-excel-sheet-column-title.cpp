class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans ="";
        while(columnNumber > 0){
            ans.push_back((columnNumber-1)%26 + 'A');
            columnNumber = (columnNumber-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// A 1
// Z 26
// AA 27
// AZ 52
// AAA 703
// AAZ 728