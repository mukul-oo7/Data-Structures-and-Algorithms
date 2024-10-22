class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string str = "";
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        // cout << alpha.size() <<endl;

        for(int i=0; i<target.size(); i++){

            int j=0;
            while(target[i]!=alpha[j]){
                ans.push_back(str+alpha[j]);
                j=(j+1)%26;
            }
            str.push_back(alpha[j]);
            ans.push_back(str);
        }

        return ans;
    }
};