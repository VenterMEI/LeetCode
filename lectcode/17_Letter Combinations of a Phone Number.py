"""
Runtime: 32 ms, faster than 98.44% of Python3 online submissions for Letter Combinations of a Phone Number.
Memory Usage: 13.2 MB, less than 51.68% of Python3 online submissions for Letter Combinations of a Phone Number.
"""

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        int2char = {"2":['a','b','c'],"3":['d','e','f'],"4":['g','h','i'],"5":['j','k','l'],"6":['m','n','o'],"7":['p','q','r','s'],"8":['t','u','v'],"9":['w','x','y','z']}
        ret = [''] if digits else []
        
        for digit in digits:
            ret = [s+c for c in int2char[digit] for s in ret]
        
        return ret