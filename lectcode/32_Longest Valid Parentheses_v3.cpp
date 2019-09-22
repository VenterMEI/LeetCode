/*
Runtime: 4 ms, faster than 96.01% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Longest Valid Parentheses.
*/

/*
left_equal_right Leetcode的解法4
它的中断方式是left和right计算器同时归0,当left大于right的时候执行这个操作.
因为必须两者相等才更新ret，所以需要left->right扫描一遍，再right->left扫描一遍。
比如left=4,right=3,不从右往左扫描结果就会出错。
也是由于两个方向都会扫描一遍，所以当left和right相等时再更新ret才得以实现。
试想left先加到4，right再加到3，则从左至右不会更新ret。但反过来则一定有机会把ret更新。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ret = 0;
        int left = 0, right = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                ++left;
            }else{
                ++right;
            }
            if(left==right && ret<right<<1){
                ret = right<<1;
            }
            if(left<right){
                left=right=0;
            }
        }

        left = 0, right = 0;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='('){
                ++left;
            }else{
                ++right;
            }
            if(left==right && ret<right<<1){
                ret = right<<1;
            }
            if(left>right){
                left=right=0;
            }
        }
        return ret;
    }
};