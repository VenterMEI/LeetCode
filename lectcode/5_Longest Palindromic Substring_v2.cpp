/*
Runtime: 460 ms, faster than 9.18% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 187 MB, less than 12.46% of C++ online submissions for Longest Palindromic Substring.
*/

/*
note:
LCS，需要额外检查一下特殊情况
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ss(s.rbegin(),s.rend());
        s =' '+s;
        ss=' '+ss;
        vector<vector<int>> dp(s.size(),vector<int>(s.size()));
        
        for(int i=1;i<s.size();i++){
            for(int j=1;j<s.size();j++){
                if (s[i]==ss[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        
        int maxlen=0;
        string ret;
        for(int i=s.size()-1;i>=1;--i){
            for(int j=s.size()-1;j>=1;--j){
                if(maxlen<dp[i][j]){
                    int l=i-dp[i][j]+1,r=i;
                    for(;l<r && s[l]==s[r];--r,++l){
                        ;
                    }
                    if(l>=r){
                        ret=string(s,i-dp[i][j]+1,dp[i][j]);
                        maxlen=dp[i][j];
                    }
                }
            }
        }
        return ret;
    }
};