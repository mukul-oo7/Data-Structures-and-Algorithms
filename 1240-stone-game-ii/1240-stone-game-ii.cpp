class Solution {
public:
    int n;
    int helper(int ind, int m, vector<int> &piles, vector<vector<int>> &dp){
        if(ind>=n) return 0;
        if(dp[ind][m]!=-1) return dp[ind][m];

        int ans=INT_MIN, sum=0;

        for(int i=ind; i<min(n, ind+2*m); i++){
            sum+=piles[i];
            ans = max(ans, sum-helper(i+1, min(n, max(m, i-ind+1)), piles, dp));
        }

        return dp[ind][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        int score = helper(0, 1, piles, dp);

        return (accumulate(piles.begin(), piles.end(), 0)+score)/2;
    }
};