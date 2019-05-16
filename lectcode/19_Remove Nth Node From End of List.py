"""
Runtime: 40 ms, faster than 90.76% of Python3 online submissions for Remove Nth Node From End of List.
Memory Usage: 13.2 MB, less than 38.10% of Python3 online submissions for Remove Nth Node From End of List.
"""

"""
note
单链表的哨兵sentinel/dummy
mySolution_1 含哨兵
mySolution_2 不含哨兵。注释部分的设计很巧妙。
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    #mySolution_1
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        sentinel = ListNode(None) #哨兵,leetcode的solution把这个叫做dummy
        sentinel.next = head
        left_node = sentinel
        right_node = head
        for i in range(n-1):
            right_node = right_node.next
        while right_node.next:
            right_node = right_node.next
            left_node = left_node.next
        left_node.next = left_node.next.next
        return sentinel.next

class Solution:
    #mySolution_2
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        left_node,right_node = head,head
        for i in range(n):
            right_node = right_node.next
        if not right_node:  #如果此时右指针为空，说明应该移除头节点。所以返回头节点的孩子即可。
            return left_node.next   
        while right_node.next:
            right_node = right_node.next
            left_node = left_node.next
        left_node.next = left_node.next.next
        return head
