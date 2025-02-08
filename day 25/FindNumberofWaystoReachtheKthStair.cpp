# define ll long long
class Solution {
public:
    // i, jump, cangodown : ans 
    unordered_map<ll, unordered_map<ll, unordered_map<int, ll>>> dp;
    ll solve(ll ind, ll jump, int canGodown, ll k) {
     //   if (ind == k) return 1;
        if (ind > k + 1) return 0; // we'll let k+1 be bc we can go down to k from there
        if (dp.count(ind) && dp[ind].count(jump) && dp[ind][jump].count(canGodown)) return dp[ind][jump][canGodown];
        ll ways = 0;
        if (ind == k) ways++;
        if (canGodown) {
            ways += solve(ind + (1LL << jump), jump + 1, 1, k);
            ways += solve(ind - 1, jump, 0, k);
        }
        else {
            ways += solve(ind + (1LL << jump), jump + 1, 1, k);
        }
        return dp[ind][jump][canGodown] = ways;

    }
    int waysToReachStair(int k) {
        return solve(1, 0, 1, k); // we start w 1 so we can go down
    }
};
