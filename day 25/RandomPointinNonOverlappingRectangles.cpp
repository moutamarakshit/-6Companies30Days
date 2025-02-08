class Solution {
public:
    vector<int>cp; // to store the cumulative points
    vector<vector<int>>rects;

    int cntPoints(vector<int>& r) {
        int points = (r[2] - r[0] + 1) * (r[3] - r[1] + 1); // to count all the points
        // simple area formula doesnt calculate the "number of points" correctly
        return points;
    }

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        int tp = 0;
        for (auto it: rects) {
            tp += (cntPoints(it));
            cp.push_back(tp);
        }
    }
    
    vector<int> pick() {
        int num = rand() % cp.back(); // weighted random selection, rectangles w more points have more chance of being selected
        int ind = upper_bound(cp.begin(), cp.end(), num) - cp.begin(); // finding out which rectangle the point belongs to
        // [1,1,3,3], [4,4,5,5] v = [9, 13]
        // 0-8 in first, 9-12 in second
        vector<int>r = rects[ind];
        int x = rand() % (r[2] - r[0] + 1) + r[0]; 
        // (r[2] - r[0] + 1) : number of possible x-values in the rectangle.
        // rand() % .. generates a random integer from 0 to (width - 1)
        // adding r0 ensures the random x-coordinate is within the rectangle, check with [2,3,4,5] eg
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
