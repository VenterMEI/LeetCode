"""
note
Solution——Approach 2: Two Pointer Approach
左右指针从两端开始，每次选短板的指针向内移。
正确性证明：
1.水立方的高度由短板决定
2.左右指针从两端向内移动，所以宽度一定下降，只能提高短板的高度才能超越过去。
3.如果移动长板，容积一定变小。因为高度不变(见1)宽度减小。

MySolution_1完全对标的Approach_2的伪码。
MySolution_2加了一个早停。
"""

"""
Runtime: 60 ms, faster than 86.83% of Python3 online submissions for Container With Most Water.
Memory Usage: 14.5 MB, less than 55.48% of Python3 online submissions for Container With Most Water.
"""
class Solution:
    #MySolution_1
    def maxArea(self, height: List[int]) -> int:
        lp = 0
        rp = len(height)-1
        ret = 0
        while lp<rp:
            ret = max(ret,(rp-lp)*min(height[lp],height[rp]))
            if height[lp]<height[rp]:
                lp+=1
            else:
                rp-=1
        return ret

"""
Runtime: 40 ms, faster than 100.00% of Python3 online submissions for Container With Most Water.
Memory Usage: 14.4 MB, less than 67.57% of Python3 online submissions for Container With Most Water.
"""
class Solution:
    #MySolution_2
    def maxArea(self, height: List[int]) -> int:
        lp = 0
        rp = len(height)-1
        ret = 0
        maxHeight = max(height)
        while True: #没问题，当lp<=rp时，maxHeight*(rp-lp)是负数
            ret = max(ret,(rp-lp)*min(height[lp],height[rp]))
            if height[lp]<height[rp]:
                lp+=1
            else:
                rp-=1
            if ret>maxHeight*(rp-lp):
                break
        return ret

if __name__ == "__main__":
    
    height = [1,8,6,2,5,4,8,3,7]
    ret = maxArea(height)
    print(ret)
