"""
Runtime: 672 ms, faster than 92.71% of Python3 online submissions for 3Sum.
Memory Usage: 16.8 MB, less than 52.31% of Python3 online submissions for 3Sum.
"""

"""
itertools.combinations 产生组合.其实自己写就是两层for循环
tuple可以计算hash值
算法思想大概是,3数之和除了[0,0,0]之外,其它组合最多其中两数相等,那么就让a,b不等,让c可能等于a或b.
"""


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        num_dict = dict()
        ret = set()
        for num in nums:
            num_dict[num] = num_dict.setdefault(num,0)+1
        for a,b in itertools.combinations(num_dict.keys(),2):
            c = -a-b
            if c in num_dict:
                if c!=a and c!=b:
                    ret.add( tuple( sorted([a,b,c]) ) )
                elif num_dict.setdefault(c,0)>=2:
                    ret.add( tuple( sorted([a,b,c]) ) )
        if num_dict.setdefault(0,0)>=3:
            ret.add(tuple([0,0,0]))

        return [i for i in ret]


#这个算法是上面代码的思想雏形，下面代码的缺点是应对含大量重复数字的输入会TLE.
#当然也可以简单改进,先计算num_dict,再将其展开.如{0:5,1:2,3:1}扩展为[0,0,1,1,3](3sum时最多2重复,再判断全0的情况).
def threeSum(nums):
    num_set = set()
    ret = set()
    zero_count = 0
    for i in range(len(nums)):
        for j in range(i+1,len(nums)):  
            if -nums[i]-nums[j] in num_set:
                ans = tuple(sorted( [nums[i],nums[j],-nums[i]-nums[j]] ))
                if  ans not in ret:
                    ret.add( ans )
        num_set.add(nums[i])

    return [i for i in ret]