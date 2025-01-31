/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &nums) {
        int n = nums.length();
        int low = 1, high = n - 2, peak = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midV = nums.get(mid);
            if (midV > nums.get(mid - 1) && midV > nums.get(mid + 1)) {
                peak = mid;
                break;
            }
            else if (midV < nums.get(mid + 1)) low = mid + 1;
            else high = mid - 1;
        }
        int left = binarySearch(target, nums, true, 0, peak);
        if (left != -1) return left;
        return binarySearch(target, nums, false, peak, n - 1);
    }
    private:
        int binarySearch(int target, MountainArray &nums, bool asc, int low, int high) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int midV = nums.get(mid);
                if (midV == target) {
                    return mid;
                }
                if (asc) {
                    if (target > midV) {
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }
                else {
                    if (target < midV) {
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }
            }
            return -1;
        }

};
