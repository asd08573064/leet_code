
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode *now = head;
        ListNode *pre = head;
        bool first = true;
        ListNode *front = NULL;
        ListNode *end = NULL;
        ListNode *tmp_next = NULL;
        int counter = 1;
        while(now){
            if(counter == 1)
                front = now;
            if(counter == 0)
                end = now;
            tmp_next = now->next;
            if(front && end){
                ListNode *to_concate_next = end->next;
                ListNode *to_concate = reverse(front, end->next);
                ListNode *tmp = to_concate;
                while(tmp->next)    tmp = tmp->next;

                if(first){
                    head = to_concate;
                    first = false;
                }
                else{
                    pre->next = to_concate;
                }

                pre = tmp;
                tmp->next = to_concate_next;
                front = NULL;
                end = NULL;  
            }

            now = tmp_next;
            counter = (counter+1)%k;
        }
        return head;
    }
};