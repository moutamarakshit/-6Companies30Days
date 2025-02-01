class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = getGap(hBars);
        int maxV = getGap(vBars);
        int gap = min(maxH, maxV);
        return gap * gap;
    }
    int getGap(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // to count the longest increasing subsequence properly
        int maxGap = 1, curr = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] + 1 == nums[i]) {
                curr++;
                maxGap = max(curr, maxGap);
            }
            else {
                curr = 1;
            }
        }
        return maxGap + 1; // we remove 2 bars, the gap will be 3
    }
};
