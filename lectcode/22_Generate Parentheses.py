"""
Runtime: 32 ms, faster than 99.85% of Python3 online submissions for Generate Parentheses.
Memory Usage: 13.5 MB, less than 20.96% of Python3 online submissions for Generate Parentheses.
"""

"""
该算法的空间和时间复杂度取决于backtrack产生了多少有效的序列。
这个证明超过了考试范围，其结论是4^n/sqrt(n)。
"""

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def backtrack(S = '', left = 0, right = 0):
            if len(S) == 2 * n:
                ans.append(S)
                return
            #left和right记录的是'('和')'的数量
            #对S来说，加'('和')'产生的新序列S1和S2是必然不同的，所以不用考虑重复的情况。
            if left < n:    #'('的数量不会超过n。
                backtrack(S+'(', left+1, right) 
            if right < left:    #当right小于left时，才能加')'
                backtrack(S+')', left, right+1) 
        backtrack()
        return ans

