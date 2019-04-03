/*
Runtime: 24 ms, faster than 99.99% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Add Two Numbers.
*/

/*
总结：
如果不是追求极致的速度和空间，代码可以少写很多。
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
        int is_carry=0;
        ListNode *ret_head=l1;
        for(;l1->next && l2->next;l1=l1->next,l2=l2->next){
            l1->val += l2->val+is_carry;
            if(l1->val>=10){
                l1->val%=10;
                is_carry=1;
            }else{
                is_carry=0;
            }
        }
        if(l2->next){
            l1->next=l2->next;  //如果l2元素多，就把l2的元素移给l1
        }
        is_carry+=l2->val;    //l2和l1对齐的最后一个元素还没加
        while(is_carry){
            l1->val+=is_carry;
            is_carry=0;
            if(l1->val>=10){
                l1->val%=10;
                if(l1->next){
                    is_carry=1;
                    l1=l1->next;
                }else{
                    l2->next=NULL;
                    l2->val=1;
                    l1->next=l2;
                }
            }
        }
        return ret_head;
    }
};