class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({0,{i,j}});
                    isWater[i][j] = -1;
                }
            }
        }
        int drow[] = {0,0,1,-1};
        int dcol[] = {1,-1,0,0};
        while (!q.empty()) {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && isWater[nrow][ncol] == 0) {
                    vis[nrow][ncol] = dist + 1;
                    isWater[nrow][ncol] = -1;
                    q.push({dist + 1, {nrow, ncol}});
                }
            }
        }
        return vis;
    }
};
