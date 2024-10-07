class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word2.size();
        vector<int> last(n, -1);

        for(int i=word1.size()-1, j=n-1; i>=0 && j>=0; i--){
            if(word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
        }

        vector<int> ans;
        bool flag=1;

        for(int i=0, j=0; i<word1.size() && j<n; i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            } else if(flag==1 && (j==n-1 || i<last[j+1])){
                ans.push_back(i);
                flag=0;
                j++;
            }
        }

        if(ans.size()!=n) return {};

        return ans;
    }
};