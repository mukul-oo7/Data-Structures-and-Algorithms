class Solution {
public:
    vector<int> dir{-1, 0, 1, 0, -1};
    int n, m;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        vis[i][j]=true;

        for(int d=0; d<4; d++){
            int x = i+dir[d], y = j+dir[d+1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[i][j]==1){
                dfs(x, y, vis, grid);
            }
        }
    }

    int count_island(vector<vector<int>>& grid){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int res=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] && !vis[i][j]){
                    dfs(i, j, vis, grid);
                    res++;
                }
            }
        }
        cout << res << endl;

        return res;
    }

    int minDays(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();

        if(count_island(grid)!=1) return 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(count_island(grid)!=1) return 1;

                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }
};