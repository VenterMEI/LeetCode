/*
Runtime: 52 ms, faster than 16.17% of C++ online submissions for Add Two Numbers.
Memory Usage: 19.1 MB, less than 58.14% of C++ online submissions for Add Two Numbers.
*/

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
        ListNode* ret = new ListNode(0) ,*ret_copy=ret;
        int flag = 0;
        do{
            if(l1){
                flag += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                flag += l2->val;    
                l2 = l2->next;
            }
            ret_copy->next = new ListNode(flag%10);
            ret_copy = ret_copy->next;
            flag /= 10;
        }while(l1 or l2 or flag);
        return ret->next;
    }
};