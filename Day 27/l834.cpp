class Solution {
public:
    vector<vector<int>> graph;
    //number of total children below each node
    vector<int> children;
    //total distance from each to node to all nodes below it
    vector<int> distance;
    int N;
	
    void dfs(int current,int parent){
        for (auto i: graph[current])
        {
            if (i == parent){
                continue;
            }
            dfs(i,current);
            children[current] += children[i] + 1;
            distance[current] += children[i] + distance[i] + 1;
        }
        return;
    }
    
    //add total distances to all nodes above a given node to distance arrray
    void back_dfs(int current, int parent){
        distance[current] += distance[parent] + (N - children[current] - 2) - distance[current] - children[current];
        for (auto i: graph[current])
        {
            if (i == parent){
                continue;
            }
            back_dfs(i,current);
        }
    }
	
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        children = vector<int>(n,0), distance = vector<int>(n,0);
        N = n;
        
        for (auto i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        dfs(0,-1);
        for (auto i: graph[0]){
            back_dfs(i,0);
        } 
        return distance;   
    }
};
