class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0;

        int ans=INT_MAX, sum=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];

            while(sum-nums[j]>=target){
                sum-=nums[j];
                j++;
            }

            // cout << j << " " << i << endl;

            if(sum>=target)
                ans = min(ans, i-j+1);
        }

        return ans==INT_MAX?0:ans;
    }
};

// 2 3 1 2 4 3