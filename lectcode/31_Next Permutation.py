"""
Runtime: 4 ms, faster than 98.72% of C++ online submissions for Next Permutation.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Next Permutation.
"""

"""
难点一是理解题意，其次掌握规律。
"""

class Solution {
public:
    void swapNums(int lp, int rp, vector<int>& nums) {
        int tmp = nums[lp];
        nums[lp] = nums[rp];
        nums[rp] = tmp;
        return;
    }

    void reverseNums(int lp, int rp, vector<int>& nums) {
        int mid = (rp + lp) / 2;
        while (lp <= mid) {
            swapNums(rp, lp, nums);
            ++lp;
            --rp;
        }
        return;
    }


    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1){
            return;
        }
        int index = nums.size()-1;
        while(index>0){ # binary search is faster.
            --index;
            if(nums[index]<nums[index+1]){
                break;
            }
        }
        if (nums[index]>=nums[index+1]){
            reverseNums(0,nums.size()-1,nums);
            return;
        }
        int index2 = nums.size()-1;
        for(;nums[index]>=nums[index2];--index2){}
        swapNums(index,index2,nums);
        reverseNums(index+1,nums.size()-1,nums);
        return;
    }
};