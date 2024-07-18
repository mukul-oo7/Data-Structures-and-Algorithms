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
    unordered_set<TreeNode*> leafNode;
    void helper(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>> &graph){
        if(root==NULL) return;

        if(parent) graph[root].push_back(parent);

        if(root->left==NULL && root->right==NULL){
            leafNode.insert(root);
            return;
        }

        if(root->left){
            graph[root].push_back(root->left);
            helper(root->left, root, graph);
        }
        if(root->right){
            graph[root].push_back(root->right);
            helper(root->right, root, graph);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;

        helper(root, NULL, graph);
        int ans=0;

        for(auto leaf: leafNode){
            queue<pair<TreeNode*, int>> q;
            q.push({leaf, 0});
            unordered_set<TreeNode*> vis;
            vis.insert(leaf);

            while(!q.empty()){
                TreeNode* node = q.front().first;
                int steps = q.front().second;
                q.pop();

                if(steps>distance) continue;
                if(steps>0 && leafNode.find(node)!=leafNode.end()) ans++;

                for(auto it: graph[node]){
                    if(vis.find(it)==vis.end()){
                        vis.insert(it);
                        q.push({it, steps+1});
                    }
                }
            }
        }

        return ans/2;
    }
};