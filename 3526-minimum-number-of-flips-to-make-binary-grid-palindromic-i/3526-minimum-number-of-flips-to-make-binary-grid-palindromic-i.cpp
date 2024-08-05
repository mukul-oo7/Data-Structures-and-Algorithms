class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row=0, col=0, n=grid.size(), m=grid[0].size();

        for(int i=0; i<n; i++){
            int l=0, r=m-1;

            while(l<r){
                if(grid[i][l]!=grid[i][r]) row++;
                l++;
                r--;
            }
        }

        for(int i=0; i<m; i++){
            int l=0, r=n-1;

            while(l<r){
                if(grid[l][i]!=grid[r][i]) col++;
                l++;
                r--;
            }
        }

        return min(row, col);
    }
};