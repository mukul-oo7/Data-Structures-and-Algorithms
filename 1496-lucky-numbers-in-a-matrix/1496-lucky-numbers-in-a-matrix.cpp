class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int> rm(n, INT_MAX), cm(m, INT_MIN);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) rm[i] = min(rm[i], matrix[i][j]);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) cm[i] = max(cm[i], matrix[j][i]);
        }

        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==rm[i] && matrix[i][j]==cm[j]) ans.push_back(rm[i]);
            }
        }

        return ans;
    }
};