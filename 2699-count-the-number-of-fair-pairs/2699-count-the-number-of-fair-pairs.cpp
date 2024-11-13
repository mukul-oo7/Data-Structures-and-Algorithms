class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        long long ans = 0;

        for(int i=0; i<nums.size(); i++){
            auto mx_num = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);
            auto mn_num = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);

            ans+=mx_num-mn_num;
        }

        return ans;
    }
};