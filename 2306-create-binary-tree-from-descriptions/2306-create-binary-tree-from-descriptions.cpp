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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, TreeNode*> mp;
        set<int> finder;

        for(auto it: des){
            if(mp.find(it[0])==mp.end()) mp[it[0]]= new TreeNode(it[0]);
            if(mp.find(it[1])==mp.end()) mp[it[1]]= new TreeNode(it[1]);

            TreeNode *parent = mp[it[0]];
            TreeNode *child = mp[it[1]];

            if(it[2]==1){
                parent->left = child;
            } else{
                parent->right = child;
            }

            finder.insert(it[0]);
        }

        for(auto it: des){
            finder.erase(it[1]);
        }

        return mp[*finder.begin()];
    }
};