"""
Runtime: 148 ms, faster than 29.71% of Python online submissions for Merge k Sorted Lists.
Memory Usage: 17.5 MB, less than 62.41% of Python online submissions for Merge k Sorted Lists.
"""

"""
mysolution_1 
mysolution_2运行确实很快，但应该不是面试官想要的答案。
https://leetcode.com/problems/merge-k-sorted-lists/discuss/292941/My-python-solution(beats-99.51).-Very-simple
理论上，mysolution_1的时间复杂度是o(Nlogk),mysolution_2的时间复杂度是o(NlogN)。我觉得可能是测试集里有大量重复的val。
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from Queue import PriorityQueue #python2
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)  #dummy
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val,l))   #(value,elem)
        while not q.empty():
            val, node = q.get() #pop
            point.next = node
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next

"""
Runtime: 64 ms, faster than 99.46% of Python3 online submissions for Merge k Sorted Lists.
Memory Usage: 16.9 MB, less than 31.62% of Python3 online submissions for Merge k Sorted Lists.
"""

from collections import Counter
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        counter = Counter()
        for list in lists:
            while (list):
                counter[list.val] += 1
                list = list.next
        counter = sorted(counter.items(), key=lambda x:x[0])
        result = ListNode("dummy")
        orig = result
        for k in counter:
            a,b = k
            for i in range(b):
                new_node = ListNode(a)
                result.next = new_node
                result = new_node
        return orig.next