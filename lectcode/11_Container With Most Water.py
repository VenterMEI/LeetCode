"""
Runtime: 84 ms, faster than 14.96% of Python3 online submissions for Container With Most Water.
Memory Usage: 16.1 MB, less than 5.13% of Python3 online submissions for Container With Most Water.
"""

"""
note
使用的hash表，o(nlogn)的时间复杂度（排序的nlogn），o(n)的空间复杂度。
感觉还行，不知道为啥运行了怎么旧。
"""

import pdb

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = {}
        right = {}
        for i,h in enumerate(height):
            if h not in left:
                left[h] = i
                right[h] = i
                continue
            left[h] = min(i,left[h])
            right[h] = max(i,right[h])
            
        height_set = sorted(left.keys(),reverse=True)
        left_margin = len(height)
        right_margin = 0
        ret = 0
        for h in height_set:
            left_margin = min(left[h],left_margin)
            right_margin = max(right_margin,right[h])
            ret = max(ret,(right_margin-left_margin)*h)
        return ret

if __name__ == "__main__":
    
    height = [1,8,6,2,5,4,8,3,7]
    ret = maxArea(height)
    print(ret)
