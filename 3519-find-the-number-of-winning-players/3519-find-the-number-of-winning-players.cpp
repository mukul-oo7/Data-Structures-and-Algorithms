class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> ball(n, vector<int>(11, 0));

        for(auto it:pick){
            ball[it[0]][it[1]]++;
        }

        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<11; j++){
                if(ball[i][j]>=i+1){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};