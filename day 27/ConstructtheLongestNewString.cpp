class Solution {
public:
    int longestString(int x, int y, int z) {
        if (x == y) return x * 4 + z * 2;
        return 4 * min(x, y) + 2 + z * 2;
    }
};
