class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int t = 0; // in case whole grid is 0
        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};
        while (!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            t = q.front()[2];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                             grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol, t + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }
            }
        }
        return t;
    }
};
