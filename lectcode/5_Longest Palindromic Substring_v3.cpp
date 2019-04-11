/*
note:
solution —— Approach 3: Dynamic Programming
*/

/*
Runtime: 200 ms, faster than 26.34% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 26.8 MB, less than 31.36% of C++ online submissions for Longest Palindromic Substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        
        string ret;
        for(int dis=0;dis<s.size();dis++){
            for(int l=0;l+dis<s.size();l++){
                if(s[l]==s[l+dis]){
                    if(dis<=1){
                        dp[l][l+dis]=true;
                        ret = s.substr(l,dis+1);
                    }else if(dp[l+1][l+dis-1]){
                        dp[l][l+dis]=true;
                        if(ret.size()<dis+1){
                            ret = s.substr(l,dis+1);
                        }
                    }
                }
            }
        }
        return ret;
    }
};


/*
note
上下的区别在于，上一个中规中矩，按dis大小一层层刷。下一个精致一点，是按三角形来刷，值得借鉴。
*/

/*
Runtime: 184 ms, faster than 28.93% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 26.5 MB, less than 31.45% of C++ online submissions for Longest Palindromic Substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        
        string ret;
        for(int i=0;i<s.size();++i){
            for(int j=i;j>=0;--j){
                if(s[i]==s[j]){
                    if(i-j<=1){ //判断也可以写成 i-j<=2
                        dp[j][i]=true;
                        if(ret.size()<i-j+1){
                            ret = s.substr(j,i-j+1);
                        }
                    }else if(dp[j+1][i-1]){
                        dp[j][i]=true;
                        if(ret.size()<i-j+1){
                            ret = s.substr(j,i-j+1);
                        }
                    }
                }
            }
        }
        return ret;
    }
};


/*
下面代码和上一个的区别是修改了循环体内部的逻辑。
代码虽然很简约，但实际上速度掉的非常多。因为实际上进行的判断变多了。
下面这段代码是仿写自 https://leetcode.com/problems/longest-palindromic-substring/discuss/2921/Share-my-Java-solution-using-dynamic-programming.
但奇怪的是，为什么java的代码运行只要 53ms，40.4MB。
*/

/*
Runtime: 396 ms, faster than 11.68% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 26.6 MB, less than 31.45% of C++ online submissions for Longest Palindromic Substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        
        string ret;
        for(int i=0;i<s.size();++i){
            for(int j=i;j>=0;--j){
                dp[j][i] = s[i]==s[j] && (i-j<=2 || dp[j+1][i-1]);  //i-j=0 A; i-j=1 AA; i-j=2 ABA;
                if(dp[j][i] && ret.size()<i-j+1){
                    ret = s.substr(j,i-j+1);
                }
            }
        }
        return ret;
    }
};

/*
不是substr的问题，因为ret更新不了多少次。
改成不创建的话，416ms,18.8MB。所以原因仍然未知。
*/
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        
        int left=0,length=0;
        for(int i=0;i<s.size();++i){
            for(int j=i;j>=0;--j){
                dp[j][i] = s[i]==s[j] && (i-j<=2 || dp[j+1][i-1]);  //i-j=0 A; i-j=1 AA; i-j=2 ABA;
                if(dp[j][i] && length<i-j+1){
                    left=j;
                    length=i-j+1;
                }
            }
        }
        return s.substr(left,length);
    }
};