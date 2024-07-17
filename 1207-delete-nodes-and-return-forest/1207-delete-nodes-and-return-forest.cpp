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
    vector<TreeNode*> ans;

    bool helper(TreeNode* root, bool isRoot, unordered_set<int> &del){
        if(root==NULL) return false;

        if(del.find(root->val)!=del.end()){
            helper(root->left, true, del);
            helper(root->right, true, del);

            return true;
        } else{
            if(isRoot) ans.push_back(root);
            if(helper(root->left, false, del)) root->left = NULL;
            if(helper(root->right, false, del)) root->right = NULL;

            return false;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del;

        for(auto it: to_delete) del.insert(it);
        helper(root, true, del);

        return ans;
    }
};