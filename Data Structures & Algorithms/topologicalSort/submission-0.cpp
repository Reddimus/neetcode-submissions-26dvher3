class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        vector<int> adjList[101];
        for (const vector<int>& e : edges)
            adjList[e[0]].push_back(e[1]);

        vector<int> topOrder;
        char visited[101] = {};
        function<bool(int)> dfs = [&](int node) -> bool {
            if (visited[node] == 'c')
                return false;
            if (visited[node] == 'v')
                return true;

            visited[node] = 'c';
            for (const int& adj : adjList[node])
                if (!dfs(adj))
                    return false;

            topOrder.push_back(node);
            visited[node] = 'v';
            return true;
        };

        for (int node = 0; node < n; ++node)
            if (!dfs(node))
                return {};
        reverse(topOrder.begin(), topOrder.end());
        return topOrder;
    }
};
