class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 100000000);
        dist[src] = 0;
        
        for(int i = 0; i < V - 1; i++)
        {
            for(auto& edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 100000000 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(int i = 0; i < V - 1; i++)
        {
            for(auto& edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 100000000 && dist[u] + wt < dist[v])
                {
                   return {-1};
                }
            }
        }
        return dist;
    }
};
