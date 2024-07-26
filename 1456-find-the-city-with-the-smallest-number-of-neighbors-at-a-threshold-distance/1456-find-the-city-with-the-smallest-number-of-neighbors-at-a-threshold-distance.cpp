class Solution {
public:
    int dijkstra(int src, int &dt, int &v, vector<pair<int, int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dis(v, INT_MAX);
        dis[src]=0;

        int ans=0;

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            // cout << node << " ";

            for(auto it: adj[node]){
                if(d+it.second <= dt && d+it.second < dis[it.first]){
                    if(dis[it.first]==INT_MAX) ans++;
                    dis[it.first]=d+it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        // cout << endl;

        return ans;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<pair<int, int>> adj[n];

        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int ans, mn = INT_MAX;
        for(int i=0; i<n; i++){
            int r = dijkstra(i, dt, n, adj);
            if(r<=mn){
                ans=i;
                mn=r;
            }
        }

        return ans;
    }
};