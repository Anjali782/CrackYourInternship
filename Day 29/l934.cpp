class Solution {
private:
	vector < pair<int, int>> v1, v2;
	void dfs(vector<vector<int>>& grid, int i, int j, int n, vector<pair<int, int>> &v) {
		if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1){
         return;   
        } 
		grid[i][j] = 2;
		v.push_back({i, j});
		dfs(grid, i - 1, j, n, v);
		dfs(grid, i, j - 1, n, v);
		dfs(grid, i + 1, j, n, v);
		dfs(grid, i, j + 1, n, v);
	}
public:
	int shortestBridge(vector<vector<int>>& grid) {
		int n = grid.size();
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1){
					cnt++;
					if (cnt == 1){
                      dfs(grid, i, j, n, v1);   
                    } 
					else if (cnt == 2){
                       dfs(grid, i, j, n, v2);  
                    } 
					else{
                     break;   
                    } 
				}
			}
		}
		
		int ans = INT_MAX;
		for (int i = 0; i < v1.size(); ++i) {
			for (int j = 0; j < v2.size(); ++j) {
				int diff = abs(v1[i].first - v2[j].first) + abs(v1[i].second - v2[j].second) - 1; 
				ans = min(ans, diff);
			}
		}
		return ans;
	}
};
