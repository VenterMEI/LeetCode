"""
Runtime: 36 ms, faster than 99.53% of Python3 online submissions for Merge Two Sorted Lists.
Memory Usage: 13 MB, less than 79.83% of Python3 online submissions for Merge Two Sorted Lists.
"""

"""
这种题居然没有一次性bug free
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, a, b):
        if a and b: #当其中一个链表为空，将返回另一个链表赋值给上一层函数的a.next
            if a.val > b.val:
                a, b = b, a
            a.next = self.mergeTwoLists(a.next, b)
        return a or b   #a总是小的，如果a和b都存在，总是返回a给上一层函数的a.next。

