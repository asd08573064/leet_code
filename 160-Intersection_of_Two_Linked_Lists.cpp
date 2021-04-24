
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp_a = headA;
        ListNode *tmp_b = headB;
        ListNode *return_ = NULL;
        while(tmp_a || tmp_b){
            if(tmp_a){
                if(tmp_a->val < 0){
                    return_ = tmp_a;
                    break;
                }
                tmp_a->val = -(tmp_a->val);
                tmp_a = tmp_a->next;
            } 
            if(tmp_b){
                
                if(tmp_b->val < 0){
                    return_ = tmp_b;
                    break;
                }
                tmp_b->val = -(tmp_b->val);
                tmp_b = tmp_b->next;
            } 
        }
        while(headA){
            if(headA->val < 0) headA->val = -headA->val;
            headA = headA->next;
        }
        while(headB){
            if(headB->val < 0) headB->val = -headB->val;
            headB = headB->next;
        }
        return return_;
    }
};