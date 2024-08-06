class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;

        for(char ch: word) mp[ch]++;

        vector<int> v;
        for(auto it: mp) v.push_back(it.second);
        sort(v.begin(), v.end(), greater<int>());

        int ans=0;

        for(int i=0; i<v.size(); i++){
            ans+=v[i]*(i/8+1);
        }

        return ans;
    }
};