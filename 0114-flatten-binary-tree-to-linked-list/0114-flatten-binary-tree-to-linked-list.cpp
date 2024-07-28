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
    TreeNode* helper(TreeNode* root){
        if(root==NULL) return NULL;

        TreeNode* l = helper(root->left);
        TreeNode* r = helper(root->right);

        // cout << root->val << " " << (l?l->val:0) << " " << (r?r->val:0) << endl;

        root->left = NULL;
        root->right = l;
        TreeNode* temp = root;
        if(r!=NULL){
            while(temp->right!=NULL) temp=temp->right;
            temp->right=r;
        }

        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};