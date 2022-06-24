class Solution
  {
	public:
	stack<int>st;
	void dfs(int node, vector<int> adj[] , vector<int>&vis){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it , adj , vis);
	        }
	    }
	    st.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V , 0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i , adj , vis);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	     ans.push_back(st.top());
	     st.pop();
	    }
	    return ans;
	}
};
