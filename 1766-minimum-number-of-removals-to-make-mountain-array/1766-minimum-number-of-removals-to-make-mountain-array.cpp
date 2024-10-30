class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n), dec(n);
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(ans.size()==0 || ans.back()<nums[i]){
                ans.push_back(nums[i]);
                inc[i] = ans.size();
            } else{
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
                inc[i] = idx+1;
            }

        }

        ans.clear();
        for(int i=n-1; i>=0; i--){
            if(ans.size()==0 || ans.back() < nums[i]){
                ans.push_back(nums[i]);
                dec[i] = ans.size();
            } else{
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
                dec[i] = idx+1;
            }

        }

        // for(auto it: nums) cout << it << " ";
        // cout << endl;
        // for(auto it: inc) cout << it << " ";
        // cout << endl;
        // for(auto it: dec) cout << it << " ";
        // cout << endl;

        int res = n;

        for(int i=1; i<n-1; i++){
            if(inc[i]>1 && dec[i]>1)
                res = min(res, n-inc[i]-dec[i]+1);
        }

        return res;
    }
};