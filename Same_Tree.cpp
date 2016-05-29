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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        TreeNode *pNode,*qNode;
        while(!q1.empty())
        {
            pNode=q1.front();
            qNode=q2.front();
            if(pNode==NULL&&qNode==NULL)
            {
                q1.pop();
                q2.pop();
                continue;
            }
            if((pNode!=NULL&&qNode==NULL)||(pNode==NULL&&qNode!=NULL))
                return false;
            if(pNode->val!=qNode->val)
                return false;
            q1.push(pNode->left);
            q1.push(pNode->right);
            q2.push(qNode->left);
            q2.push(qNode->right);
            q1.pop();
            q2.pop();
        }
        return true;
    }
};
