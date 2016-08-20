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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        vector<vector<TreeNode*>> intermediary;
        intermediary.push_back(vector<TreeNode*>(1, root));
        result.push_back(vector<int>(1, root->val));
        for(int i = 0; i < intermediary.size(); ++i){
            vector<TreeNode*> &level = intermediary[i];
            vector<int> next_level_val;
            vector<TreeNode*> next_level;
            for(int i = 0; i < level.size(); ++i){
                if(level[i]->left != NULL){
                    next_level.push_back(level[i]->left);
                    next_level_val.push_back(level[i]->left->val);
                }
                if(level[i]->right != NULL){
                    next_level.push_back(level[i]->right);
                    next_level_val.push_back(level[i]->right->val);
                }
            }
            if(!next_level.empty()){
                intermediary.push_back(next_level);
                result.push_back(next_level_val);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
