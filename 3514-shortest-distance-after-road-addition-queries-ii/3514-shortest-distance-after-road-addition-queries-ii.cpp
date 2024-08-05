class Solution {
public:
    void deleteRange(std::set<int>& s, int u, int v) {
    auto it_u = s.upper_bound(u);
    auto it_v = s.lower_bound(v);
    
    if (it_u != s.end() && it_u != it_v) {
        s.erase(it_u, it_v);
    }
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(i);
        }

        vector<int> ans;
        // int d=n-1;
        // vector<bool> vis(n, true);
        
        for(auto it: queries){
            int u=it[0], v=it[1];
            deleteRange(st, u, v);
            ans.push_back(st.size()-1);

            // int l=u+1, r=v-1;
            // while(l<=r){
            //     if(!vis[l] && !vis[r]) break;
            //     if(vis[l]){
            //         vis[l]=false;
            //         l++;
            //         d--;
            //     }

            //     if(vis[r]){
            //         vis[r]=false;
            //         r--;
            //         d--;
            //     }
            // }

            // ans.push_back(d);
        }

        return ans;
    }
};