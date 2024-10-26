/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> dp;

    void dfslr(TreeNode* root, int height, int &current_max){
        if(root==NULL) return;

        dp[root->val] = current_max;
        current_max = max(height, current_max);

        dfslr(root->left, height+1, current_max);
        dfslr(root->right, height+1, current_max);
    }

    void dfsrl(TreeNode* root, int height, int &current_max){
        if(root==NULL) return;

        dp[root->val] = max(dp[root->val], current_max);
        current_max = max(height, current_max);

        dfsrl(root->right, height+1, current_max);
        dfsrl(root->left, height+1, current_max);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int mx = 0;
        dfslr(root, 0, mx);
        mx = 0;
        dfsrl(root, 0, mx);

        vector<int> ans;
        for(auto q: queries) ans.push_back(dp[q]);

        return ans;
    }
};