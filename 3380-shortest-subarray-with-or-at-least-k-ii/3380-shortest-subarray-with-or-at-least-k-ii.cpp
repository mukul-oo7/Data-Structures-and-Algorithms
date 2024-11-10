class Solution {
public:
    vector<int> bits;

    int add(int num, int k){
        int res = 0;

        for(int i=0; i<32; i++){
            if(num&(1<<i)){
                bits[i]++;
            }

            if(bits[i]){
                res |= (1<<i);
            }
        }

        return res;
    }

    int remove(int num, int k){
        int res=0;

        for(int i=0; i<32; i++){
            if(num&(1<<i)){
                bits[i]--;
            }

            if(bits[i]) res |= (1<<i);
        }

        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        bits.resize(32, 0);

        int ans = 1e9;

        for(int i=0, j=0; i<nums.size(); i++){
            int cb = add(nums[i], k);

            if(cb >= k){
                bool flag = false;

                while(j<i && remove(nums[j], k) >= k){
                    flag = true;
                    j++;
                }

                if(true && j<nums.size()) add(nums[j], k);

                ans = min(ans, i-j+1);
            }
        }

        return ans==1e9?-1: ans;
    }
};

// 010
// 001
// 100