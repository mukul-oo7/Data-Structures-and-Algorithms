class Solution {
    class Tries{
    public:
        int count;
        Tries *next[26];

        Tries(){
            count = 0;
            
            for(int i=0; i<26; i++) next[i]=nullptr;
        }
    };

public:
    Tries *root;
    void push(string &str){
        Tries *temp = root;

        for(char ch: str){
            int idx = ch - 'a';

            if(temp->next[idx]==NULL) temp->next[idx] = new Tries();

            temp = temp->next[idx];
            temp->count++;
        }
    }

    int prefix(string str){
        Tries *temp = root;
        int sum = 0;

        for(char ch: str){
            int idx = ch - 'a';
            temp = temp->next[idx];

            sum+=temp->count;
        }

        return sum;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Tries();

        for(string str: words) push(str);

        vector<int> ans;
        for(string str: words){
            ans.push_back(prefix(str));
        }

        return ans;
    }
};