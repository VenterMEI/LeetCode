
/*
https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
同侧异侧，以及假想INFINITY。
*/

/*
Runtime: 4 ms, faster than 79.51% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Search in Rotated Sorted Array.*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if (nums[mid]==target){
                return mid;
            }
            int midval = nums[mid]<nums[0] == target<nums[0] ? nums[mid] : target<nums[0] ? -INFINITY : INFINITY;
            if(target<midval){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
};

/*
Runtime: 4 ms, faster than 79.51% of C++ online submissions for Search in Rotated Sorted Array.
Memory Usage: 8.9 MB, less than 22.89% of C++ online submissions for Search in Rotated Sorted Array.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find(0,nums.size()-1,nums,target);
    }
    
    int find(int left, int right, vector<int>& nums, int target){
        if(right<left){
            return -1;
        }
        int mid = (left+right)/2;
        if (nums[mid]==target){
            return mid;
        }
        int midval = nums[mid]<nums[0] == target<nums[0] ? nums[mid] : target<nums[0] ? -INFINITY : INFINITY;
        if(target<midval){
            return find(left,mid-1,nums,target);
        }else{
            return find(mid+1,right,nums,target);
        }
    }
};