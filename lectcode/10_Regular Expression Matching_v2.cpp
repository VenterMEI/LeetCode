/*
Runtime: 8 ms, faster than 96.07% of C++ online submissions for Regular Expression Matching.
Memory Usage: 9.1 MB, less than 99.35% of C++ online submissions for Regular Expression Matching.
*/

/*
note：
Solution——Approach 2:Dynamic Programming
横轴是p，纵轴是s，它是从右下角一层层往上刷。
init为dp[i+1][j+1]=true
dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j]  if p[j+1]=='*'
dp[i][j] = first_match && dp[i+1][j+1]  if p[j+1]!='*'

leetcode solution还有个top-down的递归动态规划版本，从右上开始填充路过的路径。其实就是v1版本加上一个hash，所有已经计算过的节点不必再计算。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[s.size()][p.size()]=true;
        for(int i=s.size();i>=0;--i){
            for(int j = p.size()-1;j>=0;--j){
                bool first_match = i!=s.size() && (p[j]==s[i] || p[j]=='.');
                if(p[j+1]=='*'){    //当p[j]=='*'时，dp[i][j]是什么不重要，因为不会被用到。
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                    //如果dp[i+1][j]==true而且first_match=true,那么将dp[i+1][j]中*的repeat次数+1就能使dp[i][j]==true。以string ccb 和parrtern c*b为例。dp[2][0]中c重复了0次b与pattern匹配。dp[1][0]中c重复1次，cb与pattern匹配。dp[0][0]中c重复了2次，cbb和pattern匹配。
                }else{
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};