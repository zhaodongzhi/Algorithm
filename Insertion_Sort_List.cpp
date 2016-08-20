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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* _head = new ListNode(0);
        _head->next = head;
        head = _head;
        for(ListNode* cur = head->next; cur->next != NULL;){
            ListNode* prev = head;
            for(;prev != cur; prev = prev->next){
                if(prev->next->val > cur->next->val){
                    ListNode* insert = cur->next;
                    cur->next = cur->next->next;
                    insert->next = prev->next;
                    prev->next = insert;
                    break;
                }
            }
            if(prev == cur) cur = cur->next;
        }
        head = _head->next;
        delete _head;
        return head;
    }
};
