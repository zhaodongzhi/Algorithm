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
    int maxDepth(TreeNode *root) {
        queue<TreeNode*> q;
        if(root==NULL)
            return 0;
        q.push(root);
        int depth = 0;
        TreeNode* node;
        
        while(!q.empty())
        {
            ++depth;
            
            for(int i = 0, n = q.size(); i < n; ++i){
                node = q.front();
                q.pop();
                if(NULL != node->left){
                    q.push(node->left);
                }
                if(NULL != node->right){
                    q.push(node->right);
                }
            }
        }
       return depth; 
    }
};
