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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if(root == NULL){
            return result;
        }
        s.push(root);
        while(s.top()->left != NULL){
            s.push(s.top()->left);
        }
        while(!s.empty()){
            TreeNode *child = s.top();
            s.pop();
            result.push_back(child->val);
            if(child->right != NULL){
                s.push(child->right);
                while(s.top()->left != NULL){
                    s.push(s.top()->left);
                }
            }
        }
        return result;
    }
};
