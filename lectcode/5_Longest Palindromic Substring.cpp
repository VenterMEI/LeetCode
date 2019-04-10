/*
Runtime: 64 ms, faster than 56.88% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 12.5 MB, less than 54.79% of C++ online submissions for Longest Palindromic Substring.
*/

/*
Solution —— Approach 4: Expand Around Center
思想和Approach 4是一致的。速度上两者没什么差别，但是代码上Approach 4将奇数回文和偶数回文都调用同一个函数，简约的多。值得学习。
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ret;
        //odd number
        for(string::const_iterator cps=s.cbegin();cps!=s.cend();++cps){
            string::const_iterator l=cps,r=cps; //[l+1,r-1]才是回文
            while(l>=s.cbegin() && r<s.cend() && *l==*r){   //先判断是否越界，再比较是否相等。
                --l;++r;
            }
            if(ret.length()<r-l-1){
                ret = string(l+1,r);
            }
        }
        
        //even number
        for(string::const_iterator cps=s.cbegin();cps!=s.cend();++cps){
            string::const_iterator l=cps,r=cps+1;
            while(l>=s.cbegin() && r<s.cend() && *l==*r){
                --l;++r;
            }
            if(ret.length()<r-l-1){
                ret = string(l+1,r);
            }
            
        }
        return ret;
    }
};