class Solution {
public:
    vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};
    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        for(auto d: dir){
            int r = d[0], c=d[1];
            if(i+r>=0 && i+r<grid.size() && j+c>=0 && j+c<grid[0].size() && grid[i+r][j+c]>grid[i][j]){
                ans = max(ans, 1+helper(i+r, j+c, grid, dp));
            }
        }

        return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans=0;

        for(int i=0; i<n; i++){
            ans = max(ans, helper(i, 0, grid, dp));
        }

        return ans;
    }
};