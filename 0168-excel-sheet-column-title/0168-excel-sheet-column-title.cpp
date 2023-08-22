class Solution {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle((n - 1) / 26) + (char) ((n - 1) % 26 + 'A');
    }
};

// A 1
// Z 26
// AA 27
// AZ 52
// AAA 703
// AAZ 728