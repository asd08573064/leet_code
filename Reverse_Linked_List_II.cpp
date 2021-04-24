/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct sol{
        ListNode* front;
        ListNode* end;
    };
    ListNode* reverse(ListNode* front, ListNode* end){
        ListNode* now = front;
        ListNode* next_node = NULL;
        if(front->next) next_node = front->next;
        ListNode* pre = NULL;
        while(next_node && next_node != end){
            ListNode* tmp =  next_node->next;
            next_node->next = now;
            now->next = pre;
            pre = now;
            now = next_node;
            next_node = tmp;
        }
        return now;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right == left) return head;
        ListNode *tmp_head =  head;
        ListNode *tmp_end =  head;
        ListNode *pre_head = head;
        ListNode *to_concate = NULL;

        for(int i = 0; i < left-1; i++){
            pre_head = tmp_head;
            tmp_head = tmp_head->next;
        }

        tmp_end = tmp_head;

        for(int i = left; i< right; i++){
            tmp_end = tmp_end->next;
        }
        
        to_concate = tmp_end->next;

        if(tmp_head == head)
            head = reverse(tmp_head, tmp_end->next);
        else
            pre_head->next = reverse(tmp_head, tmp_end->next);
        
        tmp_head = head;
        
        while(tmp_head->next)   
            tmp_head = tmp_head->next;
        
        tmp_head->next = to_concate;
        
        return head;
    }
};

