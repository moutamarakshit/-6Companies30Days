class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        sort(arr2.begin(), arr2.end());
        for (auto it: arr1) {
            auto lb = lower_bound(arr2.begin(), arr2.end(), it - d);
            if (lb != arr2.end() && *lb <= it + d) continue;
            cnt++;
        }
        return cnt;
    }
};
// |x-y| <= d
// -d <= x-y <= d
// x-d <= y <= x+d
// so we find out lb of x-d and if it's within x+d, meaning it cant be counted
