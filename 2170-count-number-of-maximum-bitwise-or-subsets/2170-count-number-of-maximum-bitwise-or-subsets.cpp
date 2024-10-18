class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for(int mask=1; mask<(1<<n); mask++){
            int cur_or = 0;

            for(int j=0; j<n; j++){
                if(mask&(1<<j)){
                    cur_or|=nums[j];
                }
            }

            mp[cur_or]++;
        }

        int ans = 0;
        for(auto it: mp) ans = it.second;

        return ans;
    }
};