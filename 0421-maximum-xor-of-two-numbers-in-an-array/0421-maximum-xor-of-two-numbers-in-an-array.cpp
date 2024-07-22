class Solution {
public:
    class TrieNode{
        public:
        TrieNode *child[2];

        TrieNode(){
            this->child[0]=NULL;
            this->child[1]=NULL;
        }
    };

    TrieNode *root = new TrieNode();

    void insert(int num){
        TrieNode *temp = root;

        for(int i=31; i>=0; i--){
            bool bit = (num >> i) & 1;

            if(!temp->child[bit]) temp->child[bit] = new TrieNode();
            temp=temp->child[bit];
        }
    }

    int findMax(int num){
        TrieNode *temp = root;
        int res = 0;

        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;

            if(temp->child[!bit]){
                res |= (1<<i);
                temp = temp->child[!bit];
            } else{
                temp = temp->child[bit];
            }
        }

        return res;
    }



    void traverse(TrieNode *root, string prefix = "") {
        if (root->child[0] == NULL && root->child[1] == NULL) {
            cout << prefix << endl;
            return;
        }
        if (root->child[0]) {
            traverse(root->child[0], prefix + "0");
        }
        if (root->child[1]) {
            traverse(root->child[1], prefix + "1");
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        for(auto num: nums){
            insert(num);
        }

        int ans=0;
        for(auto num: nums){
            ans = max(ans, findMax(num));
        }

        // traverse(root, "");

        return ans;
    }
};