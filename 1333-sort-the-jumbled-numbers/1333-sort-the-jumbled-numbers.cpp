class Solution {
public:
    int newDigit(int num, vector<int> &mapping){
        if(num==0) return mapping[0];

        int new_num = 0, tmp=1;

        while(num>0){
            int d = num%10;
            num/=10;
            new_num = tmp*mapping[d]+new_num;
            tmp*=10;
        }

        return new_num;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num] = newDigit(num, mapping);

        sort(nums.begin(), nums.end(), [&mp](int a, int b){
            return mp[a]<mp[b];
        });

        return nums;
    }
};