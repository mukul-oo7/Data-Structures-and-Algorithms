class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=words[0].size();
        int ws = words.size();

        if(s.size() < n*ws) return {};
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) mp[words[i]]=i;

        unordered_map<int, int> fre;
        for(int i=0; i<words.size(); i++){
            fre[mp[words[i]]]++;
        }

        vector<int> v;
        

        for(int i=0; i<s.size()-n+1; i++){
            string str = s.substr(i, n);
            if(mp.find(str)!=mp.end()) v.push_back(mp[str]);
            else v.push_back(-1);
        }

        vector<int> res;

        for(int i=0; i<v.size(); i++){

            if(v[i]!=-1){
                unordered_map<int, int> temp;

                int j=i+n;

                for(int j=i, k=0; j<v.size() && k<ws && v[j]!=-1; j+=n, k++){
                    temp[v[j]]++;
                }

                res.push_back(i);

                for(auto &[idx, count]: fre){
                    if(temp[idx]!=count){
                        res.pop_back();
                        break;
                    }
                }
            }
        }

        return res;
    }
};

// abcdef