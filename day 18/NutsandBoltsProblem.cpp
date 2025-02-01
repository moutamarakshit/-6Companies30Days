void matchPairs(int n, char nuts[], char bolts[]) {
        unordered_map<char, int>mpp;
        mpp['!'] = 0;
        mpp['#'] = 1;
        mpp['$'] = 2;
        mpp['%'] = 3;
        mpp['&'] = 4;
        mpp['*'] = 5;
        mpp['?'] = 6;
        mpp['@'] = 7;
        mpp['^'] = 8;
        sort(nuts, nuts + n, [&](char&a, char&b) {
            return mpp[a] < mpp[b];
        });
        sort(bolts, bolts + n, [&] (char& a, char&b) {
            return mpp[a] < mpp[b];
        });
    }
