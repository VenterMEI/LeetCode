"""
Runtime: 248 ms, faster than 99.85% of Python3 online submissions for 3Sum.
Memory Usage: 17.4 MB, less than 17.54% of Python3 online submissions for 3Sum.
"""

"""
note
bisect 二分查找/插入
将问题分为含重复数字和不含重复数字两种情况来处理.
"""

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        count={}
        for num in nums:
            if num not in count:
                count[num]=0
            count[num]+=1
        nums=sorted(count)
        res=[]
        for i,n in enumerate(nums):
            #组合含重复数字
            if count[n] >= 2 :
                if n==0 :
                    if count[n]>=3 :
                        res.append([0,0,0])
                else: 
                    if -2*n in count:
                        res.append([n,n,-2*n])
            #组合中数字全不一样
            if n<0: #你想想为什么规定n<0
                twosum=-n
                left=bisect.bisect_left(nums,twosum-nums[-1],i+1)   #左边界，注意参数lo=i+1意味着起始查找的位置比i要大。
                right=bisect.bisect_right(nums,twosum//2,left)  #右边界,注意是twosum//2,也即j小于二分之一twosum，comp大于二分之一twosum
                #上两步确保即n<j<comp。那么现在回到为什么要判断n<0，那是避免无效计算。最小值都大于等于0，那么无重复数字组合的和不会小于0.
                for j in nums[left:right]:  #用左右边界减少查询次数.
                    comp = twosum - j
                    if comp in count and comp != j: #comp==j的情况在"组合含重复数字"处处理
                        res.append([n,j,comp])
        return res

