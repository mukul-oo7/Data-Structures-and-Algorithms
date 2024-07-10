class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;

        for(auto str: logs){
            if(str=="./") continue;
            if(str=="../") ans = max(0, ans-1);
            else ans++;
        }

        return ans;
    }
};