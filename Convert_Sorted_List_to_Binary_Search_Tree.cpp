/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* begin, ListNode* end){
        if(begin == end) return NULL;
        ListNode* slow = begin;
        ListNode* fast = begin;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(begin, slow);
        node->right = sortedListToBST(slow->next, end);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = sortedListToBST(head, NULL);
        return root;
    }
};
