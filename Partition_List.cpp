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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* small_head = new ListNode(0);
        ListNode* big_head = new ListNode(0);
        
        ListNode* small_cur = small_head;
        ListNode* big_cur = big_head;
        
        for(ListNode* cur = head; cur != NULL; cur = cur->next){
            if(cur->val < x){
                small_cur->next = new ListNode(cur->val);
                small_cur = small_cur->next;
            }
            else{
                big_cur->next = new ListNode(cur->val);
                big_cur = big_cur->next;
            }
        }
        ListNode* temp_big_head = big_head;
        big_head = big_head->next;
        delete temp_big_head;
        small_cur->next = big_head;
        ListNode* temp_small_head = small_head;
        small_head = small_head->next;
        delete temp_small_head;
        return small_head;
    }
};
