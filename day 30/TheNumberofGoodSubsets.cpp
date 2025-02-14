#define ll long long
class Solution {
public:
    
    int numberOfGoodSubsets(vector<int>& nums) {
        int mod = 1e9 + 7;
        vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        vector<ll>freq(31, 0); // for numbers from 1 to 30
        for (auto it: nums) freq[it]++;

        vector<int>numMask(31, 0);
        for (int i = 2; i <= 30; i++) {
            int num = i;
            int mask = 0;
            bool isValid = true;
            for (int j = 0; j < 10; j++) {
                int p = 0;
                while (num % primes[j] == 0) {
                    p++;
                    num /= primes[j];
                }
                if (p > 1) { 
                    isValid = false;
                    break;
                }
                if (p == 1) mask |= (1 << j);
            }
            numMask[i] = isValid ? mask : 0;
        }

        vector<ll>dp(1 << 10, 0); // there will be 1<<10 states
        dp[0] = 1; // empty subset
        for (int i = 2; i <= 30; i++) {
            if (freq[i] == 0 || numMask[i] == 0) continue;
            for (int j = (1 << 10) - 1; j >= 0; j--) {
                if ((numMask[i] & j) == 0) {
                    dp[j | numMask[i]] = (dp[j | numMask[i]] + dp[j] * freq[i]) % mod;
                }
            }
        }
        
        ll ways  = 0;
        for (int i = 1; i < (1 << 10); i++) {
            ways = (ways + dp[i]) % mod;
        }

        // handling 1's separately
        ll pow2 = 1;
        for (int i = 0; i < freq[1]; i++) {
            pow2 = (pow2 * 2) % mod;
        }
        return (ways * pow2) % mod;
    }
};
