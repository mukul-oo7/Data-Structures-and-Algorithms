class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<int> dir{-1, 0, 1, 0, -1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int res = 0;

        while(!q.empty()){
            res++;

            int sz = q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(int d = 0; d<4; d++){
                    int x = i+dir[d], y = j+dir[d+1];

                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }

        for(auto v: grid){
            for(auto e: v) if(e == 1) return -1;
        }

        return res == 0? 0: res-1;
    }
};