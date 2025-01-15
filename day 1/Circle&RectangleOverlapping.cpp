class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xc = max(x1, min(x2, xCenter));
        int yc = max(y1, min(y2, yCenter));
        int dist = (xc - xCenter) * (xc - xCenter) + (yc - yCenter) * (yc - yCenter);
        return dist <= radius * radius;
    }
};
