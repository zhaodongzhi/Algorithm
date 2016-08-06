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
    TreeNode* buildTree(int p_begin, int p_end, int i_end, const vector<int>& postorder, unordered_map<int, int>& inorder_index){
        if(p_begin > p_end){
            return NULL;
        }
        int value = postorder[p_end];
        TreeNode *r = new TreeNode(value);
        r->right = buildTree(p_end-(i_end-inorder_index[value]), p_end-1, i_end, postorder, inorder_index);
        r->left = buildTree(p_begin, p_end-(i_end-inorder_index[value])-1, inorder_index[value]-1, postorder, inorder_index);
        return r;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_index;
        for(int i = 0; i < inorder.size(); ++i){
            inorder_index[inorder[i]] = i;
        }
        TreeNode *r = buildTree(0, postorder.size()-1, inorder.size()-1, postorder, inorder_index);
        return r;
    }
};
