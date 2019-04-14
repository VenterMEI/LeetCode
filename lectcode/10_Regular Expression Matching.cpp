/*
note：
Solution——Approach 1:Recursion
无*的解决方案
    def match(text, pattern):
        if not pattern: return not text #同时为空为True
        first_match = bool(text) and pattern[0] in {text[0], '.'}
        return first_match and match(text[1:], pattern[1:])
在无*方案基础上改写成有*方案
    def isMatch(self, text, pattern):
            if not pattern:
                return not text

            first_match = bool(text) and pattern[0] in {text[0], '.'}

            if len(pattern) >= 2 and pattern[1] == '*':
                return (self.isMatch(text, pattern[2:]) or first_match and self.isMatch(text[1:], pattern))
            else:
                return first_match and self.isMatch(text[1:], pattern[1:])
不能直接改成非递归方案，因为对于*必须两条路都走。
所以递归还是要好好掌握，乍一看无*方案感觉很花里胡哨，但再看看下面改写的有*方案才知道它的匠心。

No.1代码使用了substr导致速度非常慢，原因和5_Longest Palindromic Substring_v4.cpp类似。
我也尝试了将substr改用string(s.begin(),s.end())的形式，结果是更慢，substr性能还好些。
那么关于如何对s截取而不涉及创建：
首先不要尝试用c风格的字符串来替代。
    见 https://leetcode.com/problems/regular-expression-matching/discuss/6006/C%2B%2B-recursive-solution-and-DP-solution
    通过const char *确实可以解决创建的开销，但关键是以const char *作为形参，传入string是无法匹配的。（c风格字符串以'\0'结尾，string必须调用c_str方法。）
    所以想用char *语言就选择c语言。
其次可以额外创建recursive函数来避开截取s的问题：
    recursive函数的参数为s,p的指针位置，用它来代替isMatch作为递归函数。
    见 https://leetcode.com/problems/regular-expression-matching/discuss/6006/C%2B%2B-recursive-solution-and-DP-solution
当然也可以改写成非递归函数：
    https://leetcode.com/problems/regular-expression-matching/discuss/5708/No-recursive-solution-in-golang.-only-3ms
    看完再写一个非递归版，写递归以及将递归该非递归都是我的弱项。
*/



/*
No.1
Runtime: 216 ms, faster than 22.95% of C++ online submissions for Regular Expression Matching.
Memory Usage: 15.1 MB, less than 25.99% of C++ online submissions for Regular Expression Matching.
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(!p.size()){
            return !s.size();  
        }
        
        bool first_match = s.size() && (s[0]==p[0] or p[0]=='.');
        if(p.size()>=2 && p[1]=='*'){
            return isMatch(s,p.substr(2)) || first_match && isMatch(s.substr(1),p);
        }else{
            return first_match && isMatch(s.substr(1),p.substr(1));
        }
    }
};