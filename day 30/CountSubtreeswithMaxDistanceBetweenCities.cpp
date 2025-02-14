class Solution {
public:
    int dfs(vector<vector<int>>& adj, int& no, int& res, int mask, int node) {
        no++;
        int d = 0, max_d = 0;
        for (auto it: adj[node]) {
            // if it's present in the subset and unvisited
            if (mask & (1 << it)) {
                d = 1 + dfs(adj, no, res, mask ^ (1 << it), it);
                // from left to right ~ the whole path
                // so the max_d and the current diameter
                // we store the max of all such in res
                res = max(res, d + max_d);
                max_d = max(max_d, d);
            }
        }
        return max_d;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // first building the adjacency list!
        vector<vector<int>>adj(n);
        for (auto it: edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>res(n - 1, 0); // 0th index means d = 1 and so on...

        // we'll start checking the subsets from 3 bc every valid subtree must have 2 nodes and 3 is the first number
        // with 2 set bits (0011 ~ 0th city(1st node) and 1st city (2nd node)
        // we check till 1 << n bc that's the number of possible subsets!
        for (int s = 3; s < (1 << n); s++) {
            for (int i = 0; i < n; i++) {
                // ith bit is set, ith city in unvisited
                if (s & (1 << i)) {
                    int nodes = 0, d = 0;
                    // s ^ (1 << i) means toggling the bit = marking that city as visited !!!
                    dfs(adj, nodes, d, s ^ (1 << i), i);
                    // d must be > 0 bc otherwise the subset had just one node or 
                    // no valid path was found
                    // number of nodes (1's) is equal to the number of set bits = all unvisited cities are visited
                    if (d > 0 && nodes == bitset<16>(s).count())
                        res[d - 1]++;
                    break;
                }
            }
        }
        return res;

    }
};
