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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode *curr = root;

        while (curr) {
            if (!curr->left) {
                // Process current node
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    // Make thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread
                    pred->right = nullptr;

                    // Process current node
                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap values of the two incorrect nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};