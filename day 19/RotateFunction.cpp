class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, F = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (i * nums[i]);
        }
        int ans = F;
        for (int i = 1; i < n; i++) {
            F = F + sum - n * nums[n - i];
            ans = max(ans, F);
        }
        return ans;
    }
};
