class Solution {
public:
    void sieveOfEratosthenes(vector<bool>& isPrime, int maxN) {
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i < maxN; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < maxN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        int maxN = n + 1;
        vector<bool> isPrime(maxN, true);
        sieveOfEratosthenes(isPrime, maxN);

        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                ans.push_back({i, n - i});
            }
        }

        return ans;
    }
};