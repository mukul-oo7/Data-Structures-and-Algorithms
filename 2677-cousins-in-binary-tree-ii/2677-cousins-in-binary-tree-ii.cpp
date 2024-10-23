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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        int pre = root->val;

        while(!q.empty()){
            int sz=q.size(), cur_sum=0;

            for(int i=0; i<sz; i++){
                auto [node, s] = q.front();
                q.pop();

                int sum = 0;

                node->val = pre-s;

                if(node->left) sum+=node->left->val;
                if(node->right) sum+=node->right->val;

                if(node->left) q.push({node->left, sum});
                if(node->right) q.push({node->right, sum});

                cur_sum+=sum;
            }

            pre = cur_sum;
        }

        return root;
    }
};