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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
            return NULL;
        ListNode* walker1 = l1;
        ListNode* walker2 = l2;
        int num, carryover;
        carryover = 0;
        ListNode *head;
        ListNode* temp = head;
        while(walker1 || walker2 || carryover == 1){
            num = 0;
            num += carryover;
            carryover = 0;
            if(walker1){
                num += walker1->val;
                walker1 = walker1->next;
            }
            if(walker2){
                num += walker2->val;
                walker2 = walker2->next;
            }
            if(num >= 10){
                num = (num % 10);
                carryover++;
            }
            temp->val = num;
            if(walker1 || walker2 || carryover == 1){
                temp->next = new ListNode(0);
                temp = temp->next;
            }
        }
        return head;
    }
};