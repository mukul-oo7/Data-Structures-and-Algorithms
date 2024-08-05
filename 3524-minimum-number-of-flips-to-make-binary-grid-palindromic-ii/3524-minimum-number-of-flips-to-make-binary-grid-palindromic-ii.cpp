class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        int rs=0, re=n-1;
        int ans=0;

        while(rs<re){
            int cs=0, ce=m-1;

            while(cs<ce){
                int one=grid[rs][cs]+grid[rs][ce]+grid[re][cs]+grid[re][ce];
                ans+=min(one, 4-one);
                cs++;
                ce--;
            }

            rs++;
            re--;
        }

        int one=0, flip=0;

        if(n%2==1){
            int cs=0, ce=m-1;
            int row=n/2;

            while(cs<ce){
                if(grid[row][cs]!=grid[row][ce]){
                    ans++;
                    flip++;
                }
                if(grid[row][cs]==1 && grid[row][ce]==1) one++;
                cs++;
                ce--;
            }
        }

        if(m%2==1){
            int rs=0, re=n-1;
            int col=m/2;

            while(rs<re){
                if(grid[rs][col]!=grid[re][col]){
                    ans++;
                    flip++;
                }
                if(grid[rs][col]==1 && grid[re][col]==1){
                    one++;
                }
                rs++;
                re--;
            }
        }

        if(n%2==1 && m%2==1) ans+=grid[n/2][m/2];

        if(one%2==1 && flip==0) ans+=2;

        return ans;
    }
};