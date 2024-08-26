class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans=0;

        for(int i=0; i<nums.size(); i++){
            vector<int> v(10, 0);
            
            int t = nums[i];
            while(t>0){
                int d = t%10;
                t=t/10;

                if(d!=0) v[d-1]++;
            }

            int hash = 0;
            for(int i=0; i<10; i++){
                hash += v[i]*pow(10, i);
            }

            // cout << nums[i] << ": ";

            for(auto it: mp[hash]){
                int count =0;
                int t1=nums[i], t2=it;
                // cout << it << " ";

                while(t1>0 || t2>0){
                    int d1=t1%10, d2=t2%10;
                    t1/=10, t2/=10;

                    if(d1!=d2) count++;
                }

                if(count <= 2) ans++;
            }
            // cout << endl;

            mp[hash].push_back(nums[i]);
        }

        return ans;
    }
};