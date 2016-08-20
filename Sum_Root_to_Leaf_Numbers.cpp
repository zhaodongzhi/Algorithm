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
    void sumNumbers(TreeNode* node, int num, int& result_sum){
        num = num*10 + node->val;
        if(node->left == NULL && node->right == NULL){
            result_sum += num;
            return;
        }
        if(node->left != NULL){
            sumNumbers(node->left, num, result_sum);
        }
        if(node->right != NULL){
            sumNumbers(node->right, num, result_sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int result_sum;
        sumNumbers(root, 0, result_sum);
        return result_sum;
    }
};
