class Solution
{
    stack<int> st;
    bool * visited;
    
	public:
	void toposort(int src,vector<int> adj[]){
	    visited[src]=true;
	    for(auto it: adj[src])
	        if(!visited[it]){
	            toposort(it,adj);
	        }
	    st.push(src);
	}
	void scc(int src, vector<int> adj[]){
	    visited[src]=true;
	    for(auto it: adj[src])
	        if(!visited[it])
	            scc(it,adj);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> rev[V];
        visited = new bool[V];
        
        for(int i=0;i<V;i++){
            visited[i]=false;
            for(auto it: adj[i])
                rev[it].push_back(i);
        }
        
        for(int i=0;i<V;i++)
            if(!visited[i]){
                toposort(i,adj);
            }
        for(int i=0;i<V;i++){
           visited[i]=false; 
        } 
        
        int ans=0;
        
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(!visited[u]){
                scc(u,rev);
                ans++;
            }
        }
        return ans;
    }
};
