class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int l=0, r=nums[n-1]-nums[0];

        while(l<=r){
            int mid=(l+r)/2;

            int count=0;
            int j=0;

            for(int i=0; i<n; i++){
                while(nums[i]-nums[j]>mid){
                    j++;
                }

                count+=i-j;
            }

            if(count>=k){
                r=mid-1;
            } else{
                l=mid+1;
            }
        }

        return l;
    }
};