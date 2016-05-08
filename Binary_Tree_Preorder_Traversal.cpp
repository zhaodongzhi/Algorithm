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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if(root == NULL){
            return result;
        }
        s.push(root);
        while(!s.empty()){
            TreeNode* child = s.top();
            result.push_back(child->val);
            s.pop();
            if(child->right != NULL){
                s.push(child->right);
            }
            if(child->left != NULL){
                s.push(child->left);
            }
        }
        return result;
    }
};
