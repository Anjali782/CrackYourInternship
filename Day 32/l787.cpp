class Solution {
public:
    // Approach 2: Level Wise BFS 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
         vector<pair<int,int>> adj[n];
        // prepare an adjacency list
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v,w});
        }
        
        // create a distence vetor
        vector<int> disTo(n+1,INT_MAX);
        disTo[src] = 0;  // src is the source node
        
        
        queue<pair<int,int>> q;
        q.push({0,src}); // {{cost,node}}
        k = k + 1;    
        
        while(!q.empty())
        {
         
            int size = q.size();
            k--;
            if(k < 0) break;
            // Do level Wise : Traverse all stops at current level and find best path to each stop
            for(int i = 0; i < size; i++)
            {
              auto curr = q.front(); q.pop();
              int node = curr.second;
              int cost = curr.first;
                 
              for(auto it: adj[node])
              {
                if(cost + it.second < disTo[it.first])
                {
                   disTo[it.first] = cost + it.second;
                   q.push({disTo[it.first],it.first});
                }
              }
             }
        }
        
        if(disTo[dst] == INT_MAX) return -1;
        return disTo[dst];
    }
};
