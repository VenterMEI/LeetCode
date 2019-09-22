/*
Runtime: 4 ms, faster than 96.01% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 9.5 MB, less than 78.57% of C++ online submissions for Longest Valid Parentheses.
*/

/*
stack的解法难点在如何判断中断。leetcode提供stack的解法判断中断的思路可行，但不那么直观，但好像也想不出直观但看见开销一样小的办法。
可以这样理解，stack的最底部的那个数其实代表一个')',而stack中的其余数则代表'('。
其余数被pop代表配对成功，更新ret。
而当最底部的数pop则代表更新中断的位置，所以不更新ret而是更新stack。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
    stack<int> si;
    int ret=0;
    si.push(-1);
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            si.push(i);
        }else{
            si.pop();
            if(si.empty()){
                si.push(i);
            }else{
                if(ret<i-si.top()){
                    ret = i-si.top();
                }
            }
        }
    }
    return ret;
    }
};