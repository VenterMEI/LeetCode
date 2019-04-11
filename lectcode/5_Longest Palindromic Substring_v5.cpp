/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.
*/

/*
note
代码copy自 https://leetcode.com/problems/longest-palindromic-substring/discuss/2929/Accepted-4ms-c%2B%2B-solution.
主要是leetcode提供的数据集非常特别，有非常多叠字，导致这个算法非常快。
代码原理见链接下面an.james.naqi904@gmail.com的评论：
    "abcccccbads"
    say, initially, start =2;
    after executing while loop, you'll have right == 6. Then you set start = right+1 (next one), which is 7, which is the start of next potential palindrome.
代码的正确性，或者说为什么可以"while(right<len-1 && s[right+1]==s[right]){ ++right;}"：
    仍然以"abcccccbads"为例，当s[2]=c时，s[3]=c.不必看s[1]是什么，s[1-3]必不是回文,除非s[1]=s[2]=s[3]=c。那么start就从1开始并且不会结果2。
    或者说，(s[i]为中心或中心之一 and s[i+1]==s[i] and s[i-1]!=s[i]) => s[i]不是回文中心,s[i]和s[i+1]之间可能是回文中心 => 不用再判断s[i]为中心的right++;left--;
*/

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 1)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {//len-start>max_len/2 早停
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};