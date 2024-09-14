class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> bits(20, 0);

        int j=0, mxand=0, ans=0;

        for(int i=0; i<nums.size(); i++){
            int ad = 0;

            for(int k=0; k<20; k++){
                if(nums[i] & (1<<k)){
                    bits[k]++;
                }

                if(i-j+1 == bits[k]) ad += pow(2, k);
            }

            while(ad<nums[i]){
                int tempad = 0;
                for(int k=0; k<20; k++){
                    if(nums[j] & (1<<k)){
                        bits[k]--;
                    }

                    if(i-j == bits[k]) tempad += pow(2, k);
                }

                ad = tempad;
                j++;
            }

            if(ad == mxand){
                mxand = ad;
                ans = max(ans, i-j+1);
            } else if(ad > mxand){
                mxand = ad;
                ans = i-j+1;
            }
            
        }

        return ans;
    }
};