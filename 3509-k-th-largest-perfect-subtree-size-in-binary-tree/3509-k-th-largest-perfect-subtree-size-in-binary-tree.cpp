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
    pair<int, bool> helper(TreeNode* root, int &k, priority_queue<int, vector<int>, greater<int>> &pq){
        if(root==NULL) return {0, true};

        auto [lsize, lcomp] = helper(root->left, k, pq);
        auto [rsize, rcomp] = helper(root->right, k, pq);

        if(lcomp && rcomp && lsize == rsize){
            pq.push(lsize+rsize+1);
            if(pq.size()>k) pq.pop();
            return {lsize+rsize+1, true};

        }

        return {0, false};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        helper(root, k, pq);

        if(pq.size()!=k) return -1;
        return pq.top();
    }
};