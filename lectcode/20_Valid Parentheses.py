"""
Runtime: 32 ms, faster than 99.12% of Python3 online submissions for Valid Parentheses.
Memory Usage: 13.1 MB, less than 75.46% of Python3 online submissions for Valid Parentheses.
"""

class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        stack = []
        top = -1
        for c in s:
            if c in {'[','{','('}:
                top+=1
                if top>=len(stack):
                    stack.append(c)
                else:
                    stack[top] = c
            else:
                if top>=0 and ((c==']' and stack[top]=='[') or (c=='}' and stack[top]=='{') or (c==')' and stack[top]=='(')):
                    top-=1
                else:
                    return False
        if top==-1:
            return True
        else:
            return False
