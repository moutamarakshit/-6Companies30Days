class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>graph(26, vector<long long>(26, INT_MAX));
        int n = changed.size();
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = min(graph[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;
            int src = source[i] - 'a';
            int dst = target[i] - 'a';
            if (graph[src][dst] >= INT_MAX) return -1;
            ans += graph[src][dst];
        }
        return ans;
    }
};
