#define ll long long
class Solution {
public:
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
       vector<ll>dp(n + 1, 0); // stores how many people learn the secret on day [i]
       dp[1] = 1;
       int mod = 1e9 + 7;
       for (int i = 1; i <= n; i++) {
        // people on day i will share the secret with dp[i] people and it'll be stored in dp[j]
            for (int j = i + delay; j < min(i + forget, n + 1); j++) {
                dp[j] = (dp[i] % mod + dp[j] % mod) % mod;
            }
       }
       ll ans = 0;
       // say after 4 days, people forget
       // so we'll start from last 3 days
       for (int i = n - forget + 1; i <= n; i++) ans = ((ans % mod) + (dp[i] % mod)) % mod;
       return ans;
    }
};
