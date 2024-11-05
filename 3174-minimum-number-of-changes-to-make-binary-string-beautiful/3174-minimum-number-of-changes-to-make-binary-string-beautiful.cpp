class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        vector<int> v(n, 0);

        for(int i=0; i<n; i++){
            v[i] = (s[i]=='1') ? 1: 0;
        }

        int ans = 0;

        for(int i=1; i<n; i+=2){
            if(v[i-1]!=v[i]) ans++;
        }

        return ans;
    }
};