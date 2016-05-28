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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if(root == NULL){
            return result;
        }
        TreeNode* node = root;
        
        while(NULL != node){
            s.push(node);
            if(NULL != node->left){
                node = node->left;
            }
            else{
                node = node->right;
            }
        }
        
        while(true){
            node = s.top();
            s.pop();
            while(!s.empty() && node == s.top()->right){
                result.push_back(node->val);
                node = s.top();
                s.pop();
            }
            
            result.push_back(node->val);
            
            if(s.empty()){
                break;
            }
            else{
                node = s.top()->right;
                while(NULL != node){
                    s.push(node);
                    if(NULL != node->left){
                        node = node->left;
                    }
                    else{
                        node = node->right;
                    }
                }
            }
        }
        return result;
    }
};
