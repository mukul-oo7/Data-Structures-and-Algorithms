class Solution {
public:
    vector<int> divisor(vector<int> &nums){
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx+1, 0);
        
        for(int i=2; i<=mx; i++){
            spf[i] = i;
        }

        for(int i=2; i<=mx; i++){
            if(spf[i]==i){
                for(long long j=i*1LL*i; j<=mx; j+=i){
                    if(spf[j]==j)
                        spf[j] = i;
                }
            }
        }

        return spf;
    }
    int minOperations(vector<int>& nums) {
        vector<int> spf = divisor(nums);

        int ans = 0, mn=INT_MAX;
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]<=mn){
                mn = nums[i];
                continue;
            }

            nums[i] = spf[nums[i]];

            if(nums[i]>mn) return -1;
            ans++;
            mn = nums[i];
        }

        return ans;
    }
};