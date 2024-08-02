class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int none=0, n=nums.size();

        for(int i=0; i<n; i++){
            none+=nums[i];
        }

        int j=n-none, count=0;
        for(int i=j; i<n; i++){
            count+=nums[i];
        }

        int ans=INT_MAX;

        for(int i=0; i<n; i++){
            count+=nums[i];
            if(j==n) j=0;
            count-=nums[j];
            j++;

            ans = min(ans, none-count);
        }

        return ans;
    }
};