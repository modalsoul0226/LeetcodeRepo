class Solution {
public:
    vector<vector<int>> cc;
    vector<vector<int>> graph;
    vector<int> ranks;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // init
        this->graph = vector<vector<int>>(n, vector<int>());
        this->ranks = vector<int>(n, -1);
        
        // loop over edges
        for (auto edge: connections) {
            int x = edge[0];
            int y = edge[1];

            this->graph[x].push_back(y);
            this->graph[y].push_back(x);
        }

        // dfs
        this->dfs(0, -1);

        return this->cc;
    }

    int dfs(int node, int from) {
        if (from != -1)
            this->ranks[node] = this->ranks[from] + 1;
        else
            this->ranks[node] = 0;
         
        int minConnectedRank = INT_MAX;
        int isCritical = 0;

        // dfs each neighbor
        for (auto neighbor: this->graph[node]) {
            // skip the from node
            if (neighbor == from)
                continue;

            // perform dfs if it haven't been visited before
            if (this->ranks[neighbor] < 0) {
                int rank = this->dfs(neighbor, node);

                if (rank > this->ranks[node]) {
                    vector<int> criticalEdge = {node, neighbor};
                    this->cc.push_back(criticalEdge);
                }
                minConnectedRank = min(rank, minConnectedRank);

            } else
                minConnectedRank = min(this->ranks[neighbor], minConnectedRank);
        }

        return minConnectedRank;
    }
};
