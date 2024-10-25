class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        vector<string> ans;

        for(auto it: folder) st.insert(it);

        for(int i=0; i<folder.size(); i++){
            bool is = true;
            for(int j=folder[i].size()-1; j>=0; j--){

                if(folder[i][j]=='/'){
                    string str = folder[i].substr(0, j);
                    if(st.find(str)!=st.end()){
                        is = false;
                        break;
                    }
                }
            }

            if(is) ans.push_back(folder[i]);
        }

        return ans;
    }
};