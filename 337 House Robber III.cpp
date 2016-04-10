/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        return max(calc(root, true), calc(root, false));
    }

    int calc(TreeNode* node, bool choice) {
        if (node == NULL) return 0;

        map<TreeNode*, map<bool, int>>::iterator mit = f.find(node);
        if (mit != f.end()) {
            if (mit->second.find(choice) != mit->second.end()) {
                return (mit->second)[choice];
            }
        }

        int result = 0;
        if (choice) {
            result = calc(node->left, false) + calc(node->right, false) + node->val;
        } else {
            result = max(calc(node->left, true), calc(node->left, false)) + \
                     max(calc(node->right, true), calc(node->right, false));
        }
        return store_data(node, choice, result);
    }

    int store_data(TreeNode* node, bool choice, int result) {
        map<TreeNode*, map<bool, int>>::iterator mit = f.find(node);
        if (mit == f.end()) {
            mit = f.insert(pair<TreeNode*, map<bool, int>>(node, map<bool, int>())).first;
        }
        (mit->second)[choice] = result;
        return result;
    }
private:
    struct cmp {
        bool operator() (const TreeNode* a, const TreeNode* b) {
            return (long long)(a) < (long long)(b);
        }
    };

    map<TreeNode*, map<bool, int>, cmp> f;
};
