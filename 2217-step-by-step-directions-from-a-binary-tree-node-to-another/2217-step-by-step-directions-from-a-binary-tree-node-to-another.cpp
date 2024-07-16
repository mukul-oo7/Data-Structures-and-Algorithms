class Solution {
public:
    TreeNode* findStart(TreeNode* root, int startValue, unordered_map<TreeNode*, TreeNode*> &parent) {
        if (root == nullptr) return nullptr;
        if (root->val == startValue) return root;
        
        if (root->left) {
            parent[root->left] = root;
            TreeNode* leftResult = findStart(root->left, startValue, parent);
            if (leftResult != nullptr) return leftResult;
        }
        if (root->right) {
            parent[root->right] = root;
            TreeNode* rightResult = findStart(root->right, startValue, parent);
            if (rightResult != nullptr) return rightResult;
        }
        
        return nullptr;
    }

    bool findPath(TreeNode* root, TreeNode* parent,unordered_map<TreeNode*, TreeNode*> &p, int destValue, string &path) {
        if (root == nullptr) return false;
        if (root->val == destValue) return true;

        if (root->left && root->left != parent && findPath(root->left, root, p, destValue, path)) {
            path += 'L';
            return true;
        }
        if (root->right && root->right != parent && findPath(root->right, root, p, destValue, path)) {
            path += 'R';
            return true;
        }
        if (p[root] && p[root]!=parent && findPath(p[root], root, p, destValue, path)) {
            path += 'U';
            return true;
        }

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* start = findStart(root, startValue, parent);
        
        string path = "";
        findPath(start, nullptr, parent, destValue, path);
        
        reverse(path.begin(), path.end());
        return path;
    }
};
