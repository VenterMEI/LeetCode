/*
Runtime: 8 ms, faster than 99.93% of C++ online submissions for Two Sum.
Memory Usage: 10.1 MB, less than 55.10% of C++ online submissions for Two Sum.
*/

/*
总结：
显式return
unordered_map & map
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                return vector<int>{hash[target-nums[i]],i};
            }
            hash[nums[i]]=i;
        }
        vector<int> result; return result; //多余的，但没有会在OJ中报错 warning: control reaches end of non-void function
    }
};