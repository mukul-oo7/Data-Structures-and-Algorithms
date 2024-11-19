class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        unordered_map<int, int> mp;
        int j=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            mp[nums[i]]++;

            if(i-j+1>k){
                sum-=nums[j];
                mp[nums[j]]--;

                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }

            if(i-j+1==k && mp.size()==k){
                ans=max(ans, sum);
            }
        }

        return ans;
    }
};