class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int ans = 0;
        for (auto it: ages) {
            int left = upper_bound(ages.begin(), ages.end(), 0.5 * it + 7) - ages.begin();
            int right = upper_bound(ages.begin(), ages.end(), it) - ages.begin(); 
            ans += max(0, right - left - 1);
        }
        return ans;
    }
    
};
