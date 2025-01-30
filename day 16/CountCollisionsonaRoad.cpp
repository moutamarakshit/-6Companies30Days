class Solution {
public:
    int countCollisions(string d) {
        int n = d.length();
        int left = 0, right = n - 1, ans = 0;
        while (left < n && d[left] == 'L') left++;
        while (right >= 0 && d[right] == 'R') right--;
        for (int i = left; i <= right; i++) {
            if (d[i] != 'S') ans++;
        }
        return ans;
    }
};
