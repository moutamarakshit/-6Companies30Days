#define ll long long
ll dp[1001][1 << 11];
class Solution {
public:
    vector<int>primes;
    int mod = 1e9 + 7;
    ll getMask(ll num) {
        ll mask = 0;
        int temp = num;
        for (int i = 0; i < 10; i++) {
            int cnt = 0;
            while (num % primes[i] == 0) {
                cnt++;
                num /= primes[i];
            }
            if (cnt > 1) return -1;
            if (cnt == 1) mask |= (1 << (i + 1));
        }
        return mask;
    }
    ll solve(vector<int>& nums, int ind, int n, ll prodmask) {
        if (ind >= n) return 1;
        if (dp[ind][prodmask] != -1) return dp[ind][prodmask];
        ll mask = getMask(nums[ind]);
        // not considering the element;
        ll ans = solve(nums, ind + 1, n, prodmask);
        // 
        if ((prodmask & mask) == 0) {
            ans = (ans + solve(nums, ind + 1, n, prodmask | mask)) % mod;
        }
        return dp[ind][prodmask] = ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        return (solve(nums, 0, n, 1) - 1 + mod) % mod;
    }
};
