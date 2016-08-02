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
private:
    int max_path_sum;
    
    int help(TreeNode* t){
        if(t == NULL){
            return 0;
        }
        int left_path_sum = max(0, help(t->left));
        int right_path_sum = max(0, help(t->right));
        max_path_sum = max(max_path_sum, t->val + left_path_sum + right_path_sum);
        return t->val + max(left_path_sum, right_path_sum);
    }
public:
    int maxPathSum(TreeNode* root) {
        max_path_sum = 0x80000000;
        help(root);
        return max_path_sum;
    }
};
