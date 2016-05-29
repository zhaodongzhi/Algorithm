/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while(curr != NULL){
            ListNode *temp = prev;
            prev = curr;
            curr = curr->next;
            prev->next = temp;
        }
        return prev;
    }
};
