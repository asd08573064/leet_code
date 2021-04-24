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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = NULL;
        ListNode* gr_head = NULL;
        ListNode* less_tmp = NULL;
        ListNode* great_tmp = NULL;
        bool check_g = false;
        bool check_l = false;
        if(!head) return head;
        while(head != NULL){
            if (head->val >= x && !check_g){
                gr_head = new ListNode(head->val);
                great_tmp = gr_head;
                check_g = true;
            }
            else if (head->val < x && !check_l){
                less_head = new ListNode(head->val);
                less_tmp = less_head;
                check_l = true;
            }
            else{
                if(head->val < x){
                    less_tmp->next = new ListNode(head->val);
                    less_tmp = less_tmp->next;
                }
                else{
                    great_tmp->next = new ListNode(head->val);
                    great_tmp = great_tmp->next;
                }
            }
            head = head->next;
        }
        if(less_tmp){
            less_tmp->next = gr_head;
            return less_head;
        }
        return gr_head;
    }
};

