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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<vector<TreeNode*>> level_node;
        
        if(root == NULL) return result;
        
        result.push_back(vector<int>(1, root->val));
        level_node.push_back(vector<TreeNode*>(1, root));
        
        int flag = 0;
        
        for(int i = 0; i < level_node.size(); ++i){
            vector<TreeNode*>& level = level_node[i];
            
            int level_size = level.size();
            
            vector<int> level_val;
            vector<TreeNode*> next_level;
            

            for(int j = level_size-1; j >= 0; --j){
                if(flag == 1){
                    if(level[j]->left != NULL){
                        level_val.push_back(level[j]->left->val);
                        next_level.push_back(level[j]->left);
                    }
                    if(level[j]->right != NULL){
                        level_val.push_back(level[j]->right->val);
                        next_level.push_back(level[j]->right);
                    }
                }
                else{
                    if(level[j]->right != NULL){
                        level_val.push_back(level[j]->right->val);
                        next_level.push_back(level[j]->right);
                    }
                    if(level[j]->left != NULL){
                        level_val.push_back(level[j]->left->val);
                        next_level.push_back(level[j]->left);
                    }
                }
            }
            if(!level_val.empty()){
                result.push_back(level_val);
                level_node.push_back(next_level);
            }
            flag ^= 1;
        }
        
        return result;
    }
};
