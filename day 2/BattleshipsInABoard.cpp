class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>>&board) {
        board[r][c] = '.';
        int drow[] = {0,0,1,-1};
        int dcol[] = {1,-1,0,0};
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'X') {
                dfs(nrow, ncol, m, n, board);
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), battleships = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    battleships++;
                    dfs(i, j, m, n, board);
                }
            }
        }
        return battleships;
    }
};
