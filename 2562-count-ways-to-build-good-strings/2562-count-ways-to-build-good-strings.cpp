class Solution {
public:
    vector<int> dp;
    int M = 1e9+7;
    int helper(int len, int &low, int &high, int &zero, int &one){
        if(len>high) return 0;
        if(dp[len]!=-1) return dp[len];

        long long count = (len>=low && len<=high)? 1: 0;

        count+=helper(len+zero, low, high, zero, one);
        count+=helper(len+one, low, high, zero, one);

        return dp[len] = count%M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1, -1);

        return helper(0, low, high, zero, one);
    }
};