class Solution {
public:
    void horizontalCheck(vector<vector<int>> &v){
        for(auto &row: v){
            bool g = false;
            for(int i=0; i<row.size(); i++){
                if(row[i]==-1) g = true;
                else if(row[i]==2) g = false;
                else if(g) row[i]=1;
            }

            g = false;
            for(int i=row.size()-1; i>=0; i--){
                if(row[i]==-1) g = true;
                else if(row[i]==2) g = false;
                else if(g) row[i]=1;
            }
        }

    }

    void verticalCheck(vector<vector<int>> &v){
        for(int col = 0; col<v[0].size(); col++){
            bool g = false;
            for(int row = 0; row<v.size(); row++){
                if(v[row][col] == -1) g = true;
                else if(v[row][col]==2) g = false;
                else if(g) v[row][col] = 1;
            }

            g = false;
            for(int row = v.size()-1; row>=0; row--){
                if(v[row][col] == -1) g = true;
                else if(v[row][col]==2) g = false;
                else if(g) v[row][col] = 1;
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int> (n, 0));

        for(auto g: guards){
            v[g[0]][g[1]]=-1;
        }

        for(auto w: walls){
            v[w[0]][w[1]]=2;
        }

        horizontalCheck(v);
        verticalCheck(v);

        int ans = 0;
        for(auto it: v){
            for(auto e: it) if(e==0) ans++;
        }
        
        return ans;
    }
};