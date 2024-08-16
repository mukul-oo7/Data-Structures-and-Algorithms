class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx=INT_MIN, mn=INT_MAX, ans=0;
        for(auto e: arrays[0]){
            mx = max(mx, e);
            mn = min(mn, e);
        }

        cout << mx << " " << mn << endl;

        for(int i=1; i<arrays.size(); i++){
            int mxt=INT_MIN, mnt=INT_MAX;

            for(auto e: arrays[i]){
                mxt = max(mxt, e);
                mnt = min(mnt, e);
            }

            ans = max(ans, mx-mnt);
            ans = max(ans, mxt-mn);

            mx = max(mxt, mx);
            mn = min(mnt, mn);
        }

        return ans;
    }
};