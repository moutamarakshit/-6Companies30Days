class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        int drow[8] = {-1,-1,-1,0,1,1,1,0};
        int dcol[8] = {-1,0,1,1,1,0,-1,-1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; k++) {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                        sum += img[nrow][ncol] & 255; 
                        cnt++;
                    }
                }
                img[i][j] = img[i][j] ^ (sum / cnt) << 8; 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                img[i][j] = img[i][j] >> 8; 
            }
        }
        return img;
    }
};
