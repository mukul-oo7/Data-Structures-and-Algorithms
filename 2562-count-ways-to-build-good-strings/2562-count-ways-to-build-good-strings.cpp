class Solution {
public:
    vector<int> dp;
    int M = 1e9+7;
    // int helper(int len, int &low, int &high, int &zero, int &one){
    //     if(len>high) return 0;
    //     if(dp[len]!=-1) return dp[len];

    //     long long count = (len>=low && len<=high)? 1: 0;

    //     count+=helper(len+zero, low, high, zero, one);
    //     count+=helper(len+one, low, high, zero, one);

    //     return dp[len] = count%M;
    // }

    // int countGoodStrings(int low, int high, int zero, int one) {
    //     dp.resize(high+1, -1);

    //     return helper(0, low, high, zero, one);
    // }


    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+1, 0);
        dp[0]=1;

        for(int end = 1; end<=high; end++){
            if(end>=zero) dp[end] += dp[end-zero];
            if(end>=one) dp[end] += dp[end-one];

            dp[end] %= M;
        }

        int ans = 0;

        for(int i=low; i<=high; i++){
            ans+=dp[i];
            ans%=M;
        }

        return ans;
    }
};