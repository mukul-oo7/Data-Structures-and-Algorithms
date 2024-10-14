class Solution {
public:
    long long countSmaller(long long num, vector<int> &coins){
        int n=coins.size();
        long long ans = 0;

        for(int mask=1; mask < (1<<n); mask++){
            long long lcm = 0, count = 0;

            for(int j=0; j<n; j++){
                if(mask&(1<<j)){
                    count++;
                    
                    if(lcm==0) lcm = coins[j];
                    lcm = lcm*coins[j]/__gcd(lcm, (long long)coins[j]);
                }
            }

            if(count%2==0) ans-=num/lcm;
            else ans+=num/lcm;
        }

        return ans;
    }


    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 1e18;

        while(l<r){
            long long mid = (l+r) >> 1;

            long long pos = countSmaller(mid, coins);
            if(pos >= k){
                r = mid;
            } else{
                l = mid+1;
            }
        }

        return l;
    }
};