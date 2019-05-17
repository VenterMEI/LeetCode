"""
Runtime: 32 ms, faster than 99.85% of Python3 online submissions for Generate Parentheses.
Memory Usage: 13.3 MB, less than 55.54% of Python3 online submissions for Generate Parentheses.
"""

"""
用动态规划计算好闭包
思想起源于Solution Approach 3: Closure Number。(第二个代码块)
"""
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if not n :
            return []
        dp = [[] for i in range(n+1)]
        dp[0].append("")
        for i in range(1,n+1):
            for j in range(i):
                for left in dp[j]:
                    for right in dp[i-j-1]:
                        dp[i].append('({}){}'.format(left, right))
        return dp[n]



class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0: return ['']
        ans = []
        for c in range(n):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(n-1-c):
                    #不会append重复，({})……这个形式会重叠，但(……){}这个形式不会重叠。
                    ans.append('({}){}'.format(left, right))
        return ans

