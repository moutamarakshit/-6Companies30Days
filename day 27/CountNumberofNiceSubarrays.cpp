class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
    int solve(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int n = nums.size(), l = 0;
        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i] % 2;
            while (l <= i && sum > k) {
                sum -= nums[l] % 2;
                l++;
            }
            ans += (i - l + 1);
        }
        return ans;
    }
};
