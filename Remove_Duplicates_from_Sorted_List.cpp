**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while(next != NULL){
            if(curr->val == next->val){
                curr->next = next->next;
                free(next);
                next = curr->next;
            }
            else{
                curr = next;
                next = next->next;
            }
        }
        return head;
    }
};
