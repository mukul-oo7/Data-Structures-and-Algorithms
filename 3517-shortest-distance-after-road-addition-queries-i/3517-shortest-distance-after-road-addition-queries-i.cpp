class Solution {
public:
    int dfs(int node, int target, vector<bool> &vis, vector<int> adj[]){
        if(node == target) return 0;
        vis[node] = true;

        int len = 1e9;

        for(auto it: adj[node]){
            if(!vis[it])
            len = min(len, 1+dfs(it, target, vis, adj));
        }

        vis[node]=false;
        return len;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<int> ans;
    vector<vector<pair<int, int>>> adj(n);

    // Initialize the adjacency list with the initial roads
    for (int i = 1; i < n; ++i) {
        adj[i - 1].emplace_back(i, 1);  // Road from city i-1 to i with weight 1
    }

    // Function to calculate the shortest path from source to destination using Dijkstra's algorithm
    auto dijkstra = [&](int src, int dest) -> int {
        vector<int> dist(n, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == dest) return currDist;

            if (currDist > dist[u]) continue;

            for (const auto& [v, weight] : adj[u]) {
                int newDist = currDist + weight;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.emplace(newDist, v);
                }
            }
        }

        return numeric_limits<int>::max();  // If there's no path
    };

    // Process each query and find the shortest path
    for (const auto& query : queries) {
        int u = query[0], v = query[1];
        adj[u].emplace_back(v, 1);  // Adding a new road from city u to city v

        int shortestPath = dijkstra(0, n - 1);
        if (shortestPath == numeric_limits<int>::max()) {
            ans.push_back(-1);  // If no path exists
        } else {
            ans.push_back(shortestPath);
        }
    }

    return ans;

    }
};