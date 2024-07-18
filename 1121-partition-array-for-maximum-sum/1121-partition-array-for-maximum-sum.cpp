class Solution {
public:
    int n;
    int helper(int ind, int &k, vector<int> &arr, vector<int> &dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int sum=0, mx=INT_MIN;;
        for(int i=ind; i<min(n, ind+k); i++){
            mx=max(mx, arr[i]);

            sum=max(sum, (i-ind+1)*mx+helper(i+1, k, arr, dp));
        }

        return dp[ind]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        vector<int> dp(n, -1);

        return helper(0, k, arr, dp);
    }
};