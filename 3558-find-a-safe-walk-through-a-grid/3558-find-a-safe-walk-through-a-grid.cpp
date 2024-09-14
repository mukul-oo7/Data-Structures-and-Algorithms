#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dir{-1, 0, 1, 0, -1};
    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        
        // Early return if not enough health to reach the end
        if (health <= 0 || health <= grid[0][0]) return false;
        
        vector<vector<int>> maxHealth(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        maxHealth[0][0] = health - grid[0][0];
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            // Check if we reached the destination
            if (i == n-1 && j == m-1) return true;
            
            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d], nj = j + dir[d+1];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                
                int newHealth = maxHealth[i][j] - grid[ni][nj];
                if (newHealth > 0 && newHealth > maxHealth[ni][nj]) {
                    maxHealth[ni][nj] = newHealth;
                    q.push({ni, nj});
                }
            }
        }
        
        return false;
    }
};