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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cur_index = 0;
        int list_size = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        for(list_size = 0; list_size < k && fast != NULL; ++list_size){
            fast = fast->next;
        }
        if(list_size != k || k==1){
            return head;
        }
        
        ListNode* _head = new ListNode(0);
        _head->next = head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* cur_tail = _head;
        for(cur_index = 0; ; ++cur_index){
            if(cur_index%k == 0){
                if(list_size-cur_index < k) break;
                prev = cur_tail;
                cur_tail = cur;
                cur = cur_tail->next;
            }
            else{
                cur_tail->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = cur_tail->next;
            }
            if(fast != NULL){
                fast = fast->next;
                list_size += 1;
            }
        }
        ListNode* result = _head->next;
        delete _head;
        return result;
    }
};
