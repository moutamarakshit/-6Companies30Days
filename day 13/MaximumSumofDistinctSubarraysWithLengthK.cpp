class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        long long sum = 0, maxSum = 0, l = 0;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            sum += nums[i];
            if (i - l + 1 > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                sum -= nums[l];
                l++;
            } 
            if (mpp.size() == k && i - l + 1 == k) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
