class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = countIslands(grid);
        if (islands != 1) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    islands = countIslands(grid);
                    if (islands != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }

    int countIslands (vector<vector<int>>&grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int drow[4] = {0, 0, 1, -1};
        int dcol[4] = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    ans++;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nrow = r + drow[k];
                            int ncol = c + dcol[k];
                            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                             grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    
};
